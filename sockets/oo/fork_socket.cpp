#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAXPENDING 5

int main()
{
	int server_sock;
	int client_sock;
	sockaddr_in server_addr;
	sockaddr_in client_addr;
	short server_port;
	socklen_t client_len;
	int ret_val;
	unsigned char buffer[500];
	pid_t server_pid;

	server_pid = getpid();
	server_port = 9999;

	server_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (server_sock < 0)
	{
		printf("Socket failed\n");
		return 0;
	}

	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(server_port);

	ret_val = bind(server_sock, (sockaddr*)&server_addr, sizeof(server_addr));
	if (ret_val < 0)
	{
		printf("bind() failed\n");
		close(server_sock);
		return 0;
	}

	ret_val = listen(server_sock, MAXPENDING);
	if (ret_val < 0)
	{
		printf("listen() failed\n");
		return 0;
	}

	printf("server_pid:%d, getpid():%d\n", server_pid, getpid());

	while (1)
	{
		if (server_pid == getpid())
		{
			client_len = sizeof(client_addr);
			client_sock = accept(server_sock, (sockaddr*)&client_addr, &client_len);
			if (client_sock < 0)
			{
				printf("accept() failed\n");
				return 0;
			}
			printf("accept client fd: %d  pid:%d\n", client_sock, getpid());

			printf("client %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

			fork();
			printf("fork  pid:%d\n", getpid());

			if (server_pid == getpid())
			{
				close(client_sock);
			}
			else
			{
				close(server_sock);
			}
		}
		else
		{
			ret_val = read(client_sock, buffer, 499);
			printf("ret_val:%d\n", ret_val);
			buffer[ret_val] = 0;
			write(1, buffer, ret_val);
			write(client_sock, buffer, ret_val);
		}
	}
	close(server_sock);
	close(client_sock);

	return 0;
}