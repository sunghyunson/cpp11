#include <arpa/inet.h>
#include <iostream>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include <error.h>

using namespace std;

const int BUFSIZE = 512;

void error_quit(string reason) {
	cout << "FAIL: " << reason << " failed" << endl;
	exit(1);
}

void error_msg(string reason) { cout << "ERROR: " << reason << endl; }

int main(int argc, char const* argv[]) {
	int retval;

	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) {
		error_quit("socket");
	}
	cout << "sock fd: " << sock << endl;

	sockaddr_in serveraddr;
	memset(&serveraddr, 0x00, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9000);
	serveraddr.sin_addr.s_addr = htonl(INADDR_ANY);

	retval = bind(sock, (sockaddr*)&serveraddr, sizeof(serveraddr));
	if (retval < 0) {
		error_quit("bind()");
	}

	sockaddr_in clientaddr;
	socklen_t addrlen;
	char buf[BUFSIZE + 1];

	while (1) {
		addrlen = sizeof(clientaddr);
		retval = recvfrom(sock, buf, BUFSIZE, 0, (sockaddr*)&clientaddr, &addrlen);
		cout << "[UDP " << inet_ntoa(clientaddr.sin_addr) << " : " << ntohs(clientaddr.sin_port) << "]: " << endl;
		if (retval < 0) {
			perror("recffrom");
			cout << "ERROR retval: " << retval << endl;
			error_msg("recvfrom()");
			break;
		}

		buf[retval] = '\0';
		cout << "[UDP " << inet_ntoa(clientaddr.sin_addr) << " : " << ntohs(clientaddr.sin_port) << "]: " << buf
			 << endl;

		retval = sendto(sock, buf, retval, 0, (sockaddr*)&clientaddr, sizeof(clientaddr));
		if (retval < 0) {
			error_msg("sendto()");
			continue;
		}
	}
	close(sock);

	return 0;
}
