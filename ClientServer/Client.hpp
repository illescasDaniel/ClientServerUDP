#pragma once

#include <iostream>
#include <string>

using namespace std;
using namespace Poco;
using namespace Poco::Net;

class Client {
	
	string IP;
	UInt16 port;
	
public:
	
	Client(): IP("127.0.0.1"), port(10000) { }
	
	Client(const string& IP, const UInt16& port) {
		this->IP = IP;
		this->port = port;
	}
	
	void sendMessage() const {
		
		bool connected = true;
		
		SocketAddress sa(IP, port);
		DatagramSocket dgs;
		dgs.connect(sa);
		
		string message;
		
		while (connected) {
			
			getline(cin, message);
			
			if (message == "\\end") {
				connected = false;
			}
			dgs.sendBytes(message.data(), int(message.size()));
		}
	}
	
	thread sendMessageThread() {
		return thread( [=] { sendMessage(); } );
	}
};
