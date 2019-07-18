#include "header.h"

using namespace std;

int main(int argc, char* argv[]) {
	char buffer[BUFFER_LEN];
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	char temp[20];
	char chat_data[CHAT_SIZE];

	if (argc != 2) {
		cerr << "Usage: ./filename port" << endl;
		exit(0);
	}

	int server_fd, client_fd;
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		cerr << "Server: can not open socket" << endl;
		exit(0);
	}

	// listen file descriptor
	memset(&server_addr, 0x00, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(atoi(argv[1]));

	// bind
	if (bind(server_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
		cerr << "Server: can not bind local address" << endl;
		exit(0);
	}
	cout << "Waiting for clients..." << endl;

	// listen
	if (listen(server_fd, 5) < 0) {
		cerr << "Server: can not listen connect." << endl;
		exit(0);
	}

	int len;
	int msg_size;
	memset(buffer, 0x00, sizeof(buffer));
	len = sizeof(client_addr);

	char test[20];
	char Quit[5] = "quit";

	while (1) {
		client_fd = accept(server_fd, (struct sockaddr*)&client_addr, (socklen_t*)&len);

		if (client_fd < 0) {
			cerr << "Server: accept failed" << endl;
			exit(0);
		}

		inet_ntop(AF_INET, &client_addr.sin_addr.s_addr, temp, sizeof(temp));
		cout << "Server: " << temp << " client connect," << endl;

		// send message for server
		cout << "서버에서 보낼 말 :: Hello" << endl;
		char buffer[BUFFER_LEN] = {0};
		sprintf(buffer, "Hello\n");
		write(client_fd, buffer, strlen(buffer));

		// client disconnected
		cout << "Server: " << temp << " client closed." << endl;
		close(client_fd);
	}

	// server listen socket close
	close(server_fd);

	return 0;
}