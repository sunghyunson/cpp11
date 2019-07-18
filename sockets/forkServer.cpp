#include "header.h"

#define LISTEN_QUEUE_SIZE 5

void childHandler(int signal)
{
	int status;
	pid_t pid;

	while ((pid = waitpid(-1, &status, WNOHANG)) > 0)
	{
		printf("자식 프로세스 wait 결과\n");
		printf("=====================\n");
		printf("PID	            : %d\n", pid);
		printf("Exit Value 		: %d\n", WEXITSTATUS(status));
		printf("Exit Stat       : %d\n", WIFEXITED(status));
	}
}

int main()
{
	signal(SIGCHLD, childHandler);

	sockaddr_in listen_addr;
	memset(&listen_addr, 0, sizeof(listen_addr));
	listen_addr.sin_family = AF_INET;
	listen_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	listen_addr.sin_port = htons(PORT);

	int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
	int connect_fd;

	char read_buffer[BUFFER_SIZE];
	char send_buffer[BUFFER_SIZE];
	pid_t pid;

	if (bind(listen_fd, (sockaddr*)&listen_addr, sizeof(listen_addr)) == -1)
	{
		printf("bind() failed\n");
		return -1;
	}

	if (listen(listen_fd, LISTEN_QUEUE_SIZE) == -1)
	{
		printf("listen() failed\n");
		return -1;
	}

	printf("Waiting for clients....\n");

	while (1)
	{
		sockaddr_in connect_addr;
		sockaddr_in peer_addr;
		socklen_t connect_addr_length = sizeof(connect_addr);

		while ((connect_fd = accept(listen_fd, (sockaddr*)&connect_addr, &connect_addr_length)) > 0)
		{
			getpeername(connect_fd, (sockaddr*)&peer_addr, &connect_addr_length);

			// char peer_name[sizeof(peer_addr.sin_addr) + 1] = {0};
			char peer_name[25] = {0};
			sprintf(peer_name, "%s", inet_ntoa(peer_addr.sin_addr));
			printf("connected: %s:%d\n", peer_name, ntohs(peer_addr.sin_port));

			if (connect_fd < 0)
			{
				printf("Server: accept failed\n");
				exit(0);
			}
			printf("connected fd: %d\n", connect_fd);

			pid = fork();

			// child process server
			if (pid == 0)
			{
				close(listen_fd);
				int received_bytes;
				while ((received_bytes = read(connect_fd, read_buffer, BUFFER_SIZE)) > 0)
				{
					printf("%d bytes read\n", received_bytes);
					read_buffer[received_bytes] = '\0';

					fputs(read_buffer, stdout);
					fflush(stdout);

					sprintf(send_buffer, "%s", read_buffer);
					write(connect_fd, send_buffer, strlen(send_buffer));
				}
				printf("received bytes: %d\n", received_bytes);

				close(connect_fd);
				return 0; // or exit(0)
			}
			else
			{
				close(connect_fd);
			}
		}
	}
	close(listen_fd);

	return 0;
}