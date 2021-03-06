#include <arpa/inet.h>
#include <error.h>
#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

const string SERVER_ADDR = "127.0.0.1";
const int SERVER_PORT = 9999;

int main() {
	int ret_val;

	int sock;
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock < 0) {
		cerr << "ERROR socket()" << endl;
		return 0;
	}
	cout << "socket: " << sock << endl;

	sockaddr_in echo_server_addr;
	memset(&echo_server_addr, 0x00, sizeof(echo_server_addr));
	echo_server_addr.sin_family = AF_INET;
	echo_server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR.c_str());
	echo_server_addr.sin_port = htons(SERVER_PORT);

	ret_val = connect(sock, (sockaddr*)&echo_server_addr, sizeof(echo_server_addr));
	if (ret_val < 0) {
		cerr << "ERROR connect()" << endl;
		perror("connet");
		close(sock);
		return 0;
	}
	cout << "connected " << endl;

	char buffer[500] = {
		0,
	};
	while (1) {
		ret_val = read(0, buffer, sizeof(buffer) - 1);
		buffer[ret_val - 1] = 0;
		write(sock, buffer, ret_val);
		if ('q' == buffer[0]) {
			close(sock);
			return 0;
		}

		ret_val = read(sock, buffer, 499);
		cout << "Received: " << buffer << endl;
	}

	return 0;
}