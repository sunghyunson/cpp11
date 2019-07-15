#include "header.h"

using namespace std;

int main()
{
	int server_fd;
	sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(PORT);

	server_fd = socket(AF_INET, SOCK_DGRAM, 0);
	if (server_fd < 0)
	{
		cerr << "Socket() error" << endl;
		return 0;
	}

	if (bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr)) < 0)
	{
		cerr << "bind() error" << endl;
		return 0;
	}

	cout << "Server -> waiting connection request." << endl;

	int client_fd;
	sockaddr_in client_addr;
	socklen_t client_addr_size = sizeof(client_addr);
	memset(&client_addr, 0, sizeof(client_addr));

	int receved_bytes;
	int sent_bytes;
	char read_buffer[BUFFER_SIZE];
	char send_buffer[BUFFER_SIZE];

	char nickname[5][10];
	int chatter = 0;
	int portArr[5] = {-1, -1, -1, -1, -1};
	int pNum = 0;
	int i = 0;

	while (1)
	{
		sockaddr_in connect_socket;
		socklen_t connect_socket_length = sizeof(connect_socket);
		getpeername(client_fd, (sockaddr*)&client_addr, &connect_socket_length);
		char client_IP[sizeof(client_addr.sin_addr) + 1] = {0};
		sprintf(client_IP, "%s:%d", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

		cout << "client: " << client_IP << endl;

		receved_bytes = recvfrom(server_fd, read_buffer, BUFFER_SIZE, 0, (sockaddr*)&client_addr, &client_addr_size);
		cout << receved_bytes << " bytes read" << endl;
		read_buffer[receved_bytes] = 0;
		fputs(read_buffer, stdout);
		fflush(stdout);

		sprintf(send_buffer, "%s", read_buffer);
		sent_bytes =
			sendto(server_fd, send_buffer, strlen(send_buffer), 0, (sockaddr*)&client_addr, sizeof(client_addr));
	}

	close(server_fd);

	return 0;
}