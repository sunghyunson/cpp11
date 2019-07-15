#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace std;

const int BUFSIZE = 512;

void error_quit(string reason) {
	cout << "FAIL: " << reason << " failed" << endl;
	exit(1);
}

void error_msg(string reason) { cout << "ERROR: " << reason << endl; }

void handle_socket(int sock) {

}

int main(int argc, char const* argv[]) {
	int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_sock < 0) {
		error_quit("socket");
	}
	cout << "listen_sock fd: " << listen_sock << endl;

	sockaddr_in server_addr;
	memset(&server_addr, 0x00, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9000);
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

	int retval = bind(listen_sock, (sockaddr*)&server_addr, sizeof(server_addr));
	if (retval < 0) {
		error_quit("bind");
	}

	retval = listen(listen_sock, SOMAXCONN);
	cout << "listening ~~~ " << endl;
	if (retval < 0) {
		error_quit("listen");
	}

	int client_sock;
	sockaddr_in client_addr;
	int addrlen = sizeof(client_addr);
	char buf[BUFSIZE + 1];

	while (1) {
		// accept
		client_sock = accept(listen_sock, (sockaddr*)&client_addr, (socklen_t*)&addrlen);
		cout << "client_sock fd: " << client_sock << endl;
		if (client_sock < 0) {
			error_msg("accept()");
			continue;
		}

		cout << "클라이언트 접속 IP=" << inet_ntoa(client_addr.sin_addr) << " PORT=" << ntohs(client_addr.sin_port)
			 << endl;

		do {
			// receive data
			retval = recv(client_sock, buf, BUFSIZE, 0);
			if (retval < 0) {
				error_msg("recv()");
				break;
			} else if (retval == 0) {
				break;
			}

			// show data
			buf[retval] = '\0';
			cout << "\n[TCP/" << inet_ntoa(client_addr.sin_addr) << ":" << ntohs(client_addr.sin_port) << "] " << buf
				 << endl;

			// send data
			retval = send(client_sock, buf, retval, 0);
			if (retval < 0) {
				error_msg("send()");
				break;
			}
		} while (1);
		close(client_sock);
	}
	close(listen_sock);

	return 0;
}
