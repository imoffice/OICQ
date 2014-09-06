#include "client.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <string>
#include <errno.h>
#include <fcntl.h>

using namespace std;

Client:: Client() 
{
	
}

Client:: ~Client() 
{
	
}

bool Client:: create()
{
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1)
		return false;
	else
		return true;
}

bool Client:: connect_fd(string host, unsigned int const port)
{
	sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(port);
	addr.sin_addr.s_addr = inet_addr(host.c_str());

	int success = connect(sockfd, (sockaddr *)&addr, sizeof(addr));
	if (success == 0)
		return true;
	else
		return false;
}

bool Client:: send_fd(const string s) {
    int status = send(sockfd, s.c_str(), s.size(), MSG_DONTROUTE);

    if (status == -1) {
	return false;
    } else {
	return true;
    }
}


