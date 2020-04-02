#include "header.h"

using namespace std;

int main(int argc, const char** argv) {
	if (argc != 2) {
		cerr << "Usage: " << argv[0] << " IPv4-address" << endl;
		return -1;
	}

	int client_socket;
	struct sockaddr_in server_addr;
	char buff[BUFF_SIZE + 5];

	client_socket = socket(PF_INET, SOCK_STREAM, 0);
	if (client_socket == -1) {
		cerr << "socket 생성 실패" << endl;
		exit(1);
	}

	memset(&server_addr, 0x00, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(4000);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (connect(client_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
		cerr << "접속 실패" << endl;
		exit(1);
	}

	char buffer[BUFFER_LEN];
	int n = read(client_socket, buffer, BUFFER_LEN);
	cout << n << " bytes read\n";
	buffer[n] = '\0';
	fputs(buffer, stdout);
	fflush(stdout);

	close(client_socket);

	return 0;
}