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

int recvn(int s, char* buf, int len, int flags)
{
	int rcv;
	char* ptr = buf;
	int left = len;

	while(left > 0) {
		rcv = recv(s, ptr, left, flags);
		if (rcv < 0) {
			return -1;
		}
		else if (rcv == 0)  {
			break;
		}
		left -= rcv;
		ptr += rcv;
	}

	return (len -left);
}

int main(int argc, char const* argv[]) {
	int retval;

	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock < 0) {
		error_quit("socket");
	}

	sockaddr_in server_addr;
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9000);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	retval = connect(sock, (sockaddr*)&server_addr, sizeof(server_addr));
	if (retval < 0) {
		error_quit("connect");
	}

	char buf[BUFSIZE + 1];
	int len;

	while (1) {
		memset(buf, 0x00, sizeof(buf));
		cout << "[보낸데이터]" << endl;
		// if (fgets(buff, BUFSIZE + 1, stdin) == nullptr) {
		// 	break;
		// }
		cin >> buf;
		// strcpy(buf, "good morning");
		len = strlen(buf);
		if (buf[len - 1] == '\n') {
			buf[len - 1] = '\0';
		}

		if (strlen(buf) == 0) {
			break;
		}

		retval = send(sock, buf, strlen(buf), 0);
		if (retval < 0) {
			error_msg("send()");
			break;
		}
		cout << "[TCP Client]  send " << strlen(buf) << "bytes" << endl;

		retval = recvn(sock, buf, retval, 0);
		if (retval < 0) {
			error_msg("recv()");
		}
		else if (retval == 0) {
			break;
		}

		buf[retval] = '\0';
		cout << "[TCP client] receved " << strlen(buf) << "bytes" << endl;
		cout << "[DATA]: " << buf << endl;
	}
	close(sock);

	return 0;
}
