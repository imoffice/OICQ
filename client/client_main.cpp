#include <iostream>
#include "client.h"

using namespace std;

int main (void)
{	
	cout << "Please input your message:" << endl;

	Client client;
	bool create = client.create();
	
	cout << create << endl;

	bool connect =  client.connect_fd("114.215.202.112", 53000);

	cout << connect << endl;



	//bool send(const std::string s) const;
	
	string s("test 1");
	bool send = client.send_fd(s);

	cout << send << endl;

	return 0;
}
