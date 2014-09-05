#include "client.h"
//#include "Socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>

#define HOST	"114.215.202.112"
#define PORT	53000

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



