#include <arpa/inet.h>
#include <error.h>
#include <fcntl.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>

using namespace std;

const int BUFSIZE = 512;

int main(int argc, char const* argv[]) {
	int retval;

	int listen_sock = socket(AF_INET, SOCK_STREAM, 0);
	if (listen_sock < 0) {
		cerr << "socket error";
		return -1;
	}

	// u_long on = true;
	// ioctlsocket(listen_sock, FIONBIO, &on);

	int flag;
	flag = fcntl(listen_sock, F_GETFL, 0);
	fcntl(listen_sock, F_SETFL, flag | O_NONBLOCK);

	sockaddr_in serveraddr;
	memset(&serveraddr, 0x00, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);
	serveraddr.sin_port = htons(9000);
	retval = bind(listen_sock, (sockaddr*)&serveraddr, sizeof(serveraddr));
	if (retval < 0) {
		cerr << "bind error";
		return -1;
	}

	retval = listen(listen_sock, SOMAXCONN);
	if (retval < 0) {
		cerr << "listen error";
		return -1;
	}

	int client_sock;
	sockaddr_in clientaddr;
	socklen_t addrlen = sizeof(clientaddr);
	char buf[BUFSIZE + 1];

	while (1) {
		client_sock = accept(listen_sock, (sockaddr*)&clientaddr, &addrlen);
		if (client_sock < 0) {
			if (errno != EWOULDBLOCK) {
				perror("accept");
				cout << client_sock << endl;
				cout << errno << endl;
				cout << EWOULDBLOCK << endl;
				cout << EAGAIN << endl;
			}
			continue;
			break;
		}
		cout << "Accept" << endl;
	}

	return 0;
}
