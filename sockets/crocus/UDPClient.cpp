#include "header.h"

using namespace std;

int main() {
	int client_socket;
	sockaddr_in server_addr;
	socklen_t server_addr_size;
	char send_buffer[BUFFER_SIZE];
	char read_buffer[BUFFER_SIZE];

	ssize_t received_bytes;
	ssize_t sent_bytes;

	memset(&server_addr, 0, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	inet_aton("127.0.0.1", (in_addr*)&server_addr.sin_addr.s_addr);
	server_addr.sin_port = htons(PORT);

	client_socket = socket(PF_INET, SOCK_DGRAM, 0);
	if (client_socket < 0) {
		cerr << "socket() failed" << endl;
		return 0;
	}

	while (1) {
		server_addr_size = sizeof(server_addr);
		cout << "Input Data :: ";

		char msg[BUFFER_SIZE];
		fgets(msg, BUFFER_SIZE, stdin);
		sprintf(send_buffer, "%s", msg);
		sent_bytes = sendto(client_socket, send_buffer, strlen(send_buffer), 0, (sockaddr*)&server_addr, sizeof(server_addr));
		cout << "client -> sent : " << sent_bytes << endl;

		received_bytes = recvfrom(client_socket, read_buffer, BUFFER_SIZE, 0, (sockaddr*)&server_addr, &server_addr_size);
		cout << received_bytes << " bytes read" << endl;
		read_buffer[received_bytes] = 0;
		fputs(read_buffer, stdout);
		fflush(stdout);
	}

	close(client_socket);

	return 0;
}