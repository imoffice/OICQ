
// Implementation Server Socket

#include "ServerSocket.h"
#include "Socket.h"
#include "SocketException.h"
#include <iostream>

using namespace std;

ServerSocket::ServerSocket(int port) {

    if (!Socket::create()) {
        cout << "create socket error" << endl;
	//throw SocketException("Could not create server socket.");
    }

    if (!Socket::bind(port)) {
        cout << "bind port error" << endl;
    	//throw SocketException("Could not bind to port.");
    }

    if (!Socket::listen()) {
        cout << "listen error" << endl;
    	//throw SocketException("Could not listen to socket.");
    }

    cout << "create socket ok listen to port: " << port << endl;
}

ServerSocket::~ServerSocket() {
}

const ServerSocket& ServerSocket::operator << (const std::string& s) const {
    if (!Socket::send(s)) {
	//throw SocketException ("Could not write to socket.");
    }

    return *this;
}

const ServerSocket& ServerSocket::operator >> (std::string& s) const {

    if (!Socket::recv(s)) {
	//throw SocketException("Could not read form socket.");
    }
   
    return *this;
}

void ServerSocket::accept(ServerSocket& sock) {
    if (!Socket::accept(sock)) {
	//throw SocketException("Could not accept socket.");
    }

    cout << "accept sock" << endl;
}

