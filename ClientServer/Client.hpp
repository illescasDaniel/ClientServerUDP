#pragma once

#include <iostream>
#include <string>

using namespace std;
using namespace Poco;
using namespace Poco::Net;

class Client {
	
	IPAddress IP;
	UInt16 port;
	
public:
	
	Client(): IP("127.0.0.1"), port(10000) { }
	
	Client(const IPAddress& IP, const UInt16& port) {
		this->IP = IP;
		this->port = port;
	}
	
	void sendMessage() {
		
		bool connected = true;
		SocketAddress socket(IP, port);
		DatagramSocket datagram;
		datagram.connect(socket);
		
		string message;
		
		while (connected) {
			
			getline(cin, message);
			
			if (message == "\\end") {
				connected = false;
			}
			datagram.sendBytes(message.data(), int(message.size()));
		}
	}
};
