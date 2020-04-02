#include "header.h"

int main()
{
	sockaddr_in connect_addr;
	memset(&connect_addr, 0, sizeof(connect_addr));
	connect_addr.sin_family = AF_INET;
	connect_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	connect_addr.sin_port = htons(PORT);

	int connect_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(connect_fd, (sockaddr*)&connect_addr, sizeof(connect_addr)) == -1)
	{
		printf("Can not connect\n");
		return -1;
	}
	else
	{
		int read_bytes;
		int sent_bytes;
		char send_buffer[BUFFER_SIZE];
		char read_buffer[BUFFER_SIZE];
		printf("connected fd: %d\n", connect_fd);

		while(1)
		{
			printf("서버에 보낼 내용 :: ");
			fgets(send_buffer, BUFFER_SIZE, stdin);
			write(connect_fd, send_buffer, strlen(send_buffer));

			read_bytes = read(connect_fd, read_buffer, BUFFER_SIZE);
			printf("%d bytes read\n", read_bytes);
			read_buffer[read_bytes] = '\0';
			fputs(read_buffer, stdout);
			fflush(stdout);
		}
	}
	close(connect_fd);

	return 0;
}
