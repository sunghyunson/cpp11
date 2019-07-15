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

// 도메인 이름 -> IP 주소
BOOL getIPAddr(char* name, in_addr* addr) {
	hostent* ptr = gethostbyname(name);
	if (ptr == NULL) {
		return FALSE;
	}
	memcpy(addr, ptr->h_addr, ptr->h_length);
	return TRUE;
}

// IP주소 -> 도메인 이름
BOOL getDomainName(in_addr addr, char* name) {
	hostent* ptr = gethostbyaddr((char*)&addr, sizeof(addr), AF_INET);
	if (ptr == NULL) {
		return FALSE;
	}
	strcpy(name, ptr->h_name);
	return TRUE;
}
