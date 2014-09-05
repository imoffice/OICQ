
#include "ServerSocket.h"
#include "SocketException.h"
#include <string.h>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    std::cout << "running....\n";

    // Create the socket
    ServerSocket server(53000);

    while (true) {
  	ServerSocket new_sock;
	server.accept(new_sock);

	while (true) {
	    std::string data;
	    new_sock >> data;
	    new_sock << data;
	}
    }

    return 0;
}
