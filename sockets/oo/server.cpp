#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <error.h>

using namespace std;

const int MAXPENDINGS = 5;
const int SERVER_PORT = 9999;

int main() {
	int ret_val;

	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (server_socket < 0) {
		cerr << "ERROR socket()" << endl;
		return 0;
	}
	cout << "server sock: " << server_socket << endl;

	sockaddr_in echo_server_addr;
	uint16_t echo_server_port = SERVER_PORT;
	memset(&echo_server_addr, 0x00, sizeof(echo_server_addr));
	echo_server_addr.sin_family = AF_INET;
	echo_server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	echo_server_addr.sin_port = htons(echo_server_port);

	ret_val = bind(server_socket, (sockaddr*)&echo_server_addr, sizeof(echo_server_addr));
	if (ret_val < 0) {
		cerr << "ERROR bind()" << endl;
		return 0;
	}
	cout << "binding" << endl;

	ret_val = listen(server_socket, MAXPENDINGS);
	if (ret_val < 0) {
		cerr << "ERROR listen()" << endl;
		close(server_socket);
		return 0;
	}
	cout << "listening" << endl;

	int client_socket;
	sockaddr_in echo_client_addr;
	socklen_t client_length = sizeof(echo_client_addr);
	client_socket = accept(server_socket, (sockaddr*)&echo_client_addr, &client_length);
	if (client_socket < 0) {
		cerr << "ERROR accept()" << endl;
		perror("accept");
		return 0;
	}
	cout << "accepted client_socket: " << client_socket << endl;

	cout << "Connected " << inet_ntoa(echo_client_addr.sin_addr) << ":" << ntohs(echo_client_addr.sin_port) << endl;

	char buffer[500] = {
		0,
	};
	while (1) {
		ret_val = read(client_socket, buffer, sizeof(buffer) - 1);
		buffer[ret_val] = 0;
		cout << "\nRecevied: " << endl;
		write(1, buffer, ret_val);
		cout << buffer << endl;

		if ('q' == buffer[0]) {
			// close(server_socket);
			break;
		}
	}
	close(server_socket);
	close(client_socket);

	return 0;
}
