#include <arpa/inet.h>
#include <error.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

const int MAXPENDINGS = 5;
const int SERVER_PORT = 9999;

int main() {
	int ret_val;

	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	if (server_socket < 0) {
		cerr << "ERROR socket()" << endl;
		return 0;
	}

	int server_port = SERVER_PORT;
	sockaddr_in server_addr;
	memset(&server_addr, 0x00, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(server_port);

	ret_val = bind(server_socket, (sockaddr*)&server_addr, sizeof(server_addr));
	if (ret_val < 0) {
		cerr << "ERROR bind()" << endl;
		return 0;
	}

	ret_val = listen(server_socket, MAXPENDINGS);
	if (ret_val < 0) {
		cerr << "ERROR listen()" << endl;
		return 0;
	}

	int client_sock;
	sockaddr_in client_addr;
	memset(&client_addr, 0x00, sizeof(client_addr));
	socklen_t client_len = sizeof(client_addr);
	client_sock = accept(server_socket, (sockaddr*)&client_addr, &client_len);
	if (client_sock < 0) {
		cerr << "ERROR accept()" << endl;
		return 0;
	}

	cout << "Connected " << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << endl;

	fd_set fs_status;
	char buffer[500] = {
		0,
	};
	while (1) {
		FD_ZERO(&fs_status);
		FD_SET(0, &fs_status);
		FD_SET(client_sock, &fs_status);

		select(client_sock + 1, &fs_status, 0, 0, 0);
		cout << "selected " << endl;

		if (1 == FD_ISSET(client_sock, &fs_status)) {
			ret_val = read(client_sock, buffer, sizeof(buffer) - 1);
			buffer[ret_val] = 0;
			cout << "\nRecevied: " << buffer << endl;
			// write(1, buffer, ret_val);

			if ('q' == buffer[0]) {
				// close(server_socket);
				break;
			}
		}
		else if (1 == FD_ISSET(0, &fs_status)){
			ret_val = read(0, buffer, sizeof(buffer) - 1);
			write(client_sock, buffer, ret_val);
		}
	}

	close(server_socket);
	close(client_sock);

	return 0;
}
