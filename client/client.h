#ifndef _CLIENT_H
#define _CLIENT_H

#include <iostream>

using namespace std;

class Client {

public:
	Client();
	virtual ~Client();
	
	bool create();
	bool connect_fd(string, unsigned int const);
	bool send_fd(const string);

private:
	int sockfd;
};

#endif

