#include <arpa/inet.h>
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

void error_quit(string reason) {
	cout << "FAIL: " << reason << " failed" << endl;
	exit(1);
}

void error_msg(string reason) { cout << "ERROR: " << reason << endl; }

int main(int argc, char const* argv[]) {
	int retval;

	int sock = socket(AF_INET, SOCK_DGRAM, 0);
	cout << "sock fd: " << sock << endl;
	if (sock < 0) {
		error_quit("socket");
	}

	sockaddr_in serveraddr;
	memset(&serveraddr, 0x00, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_port = htons(9000);
	serveraddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	sockaddr_in peeraddr;
	socklen_t addrlen;
	char buf[BUFSIZE+1];
	int len;
	while (1) {
		memset(buf, 0x00, sizeof(buf));
		cout << "[보낸데이터]" << endl;
		// if (fgets(buff, BUFSIZE + 1, stdin) == nullptr) {
		// 	break;
		// }
		string myinput;
		getline(cin, myinput);
		strcpy(buf, myinput.c_str());
		// cin.getline(buf, BUFSIZE);
		// cin >> buf;
		len = strlen(buf);
		if (buf[len - 1] == '\n') {
			buf[len - 1] = '\0';
		}

		if (strlen(buf) == 0) {
			break;
		}

		retval = sendto(sock, buf, strlen(buf), 0, (sockaddr*)&serveraddr, sizeof(serveraddr));
		if (retval < 0) {
			error_msg("sendto()");
			continue;
		}
		cout << "[UDP client] send -> " << retval << " bytes" << endl;

		addrlen = sizeof(peeraddr);
		retval = recvfrom(sock, buf, BUFSIZE, 0, (sockaddr*)&peeraddr, &addrlen);
		if (retval < 0) {
			error_msg("recvfrom()");
			continue;
		}

		cout << "server info: " << inet_ntoa(peeraddr.sin_addr) << ":" << ntohs(peeraddr.sin_port) << endl;
	}
	close(sock);

	return 0;
}
