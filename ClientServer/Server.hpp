#pragma once

#include <iostream>
#include <cstring>

using namespace std;
using namespace Poco;
using namespace Poco::Net;

class Server {
	
	string IP;
	UInt16 port;
	int bufferSize;
	
public:
	
	Server(): IP("127.0.0.1"), port(10000), bufferSize(1024) { }
	
	Server(const string& IP, const UInt16& port, const int& bufferSize) {
		this->IP = IP;
		this->port = port;
		this->bufferSize = bufferSize;
	}
	
	void receiveMessages() const {
		
		bool connected = true;
		
		SocketAddress socket(IP, port);
		DatagramSocket datagram(socket);
		char buffer[bufferSize];
		
		cout << "Listening...\n" << endl;
		
		while (connected) {
			
			SocketAddress sender;
			
			int size = datagram.receiveFrom(buffer, bufferSize - 1, sender);
			buffer[size] = '\0';
			
			cout << sender.toString() << ": " << buffer << endl;
			
			if (string(buffer) == "\\end") {
				string senderIP = sender.host().toString();
				cerr << "\nUser: " << senderIP << " ended connection" << endl;
				connected = false; // OPTIONAL!
			}
		}
	}
	
	thread receiveMessagesThread() {
		return thread( [=] { receiveMessages(); } );
	}
};
