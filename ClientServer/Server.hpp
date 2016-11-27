#pragma once

#include <iostream>
#include <cstring>

using namespace std;
using namespace Poco;
using namespace Poco::Net;

struct Server {
	
	int bufferSize;
	SocketAddress socket;
	static bool debugModeEnabled;
	
	Server(): bufferSize(1024) { socket = SocketAddress(10000); }
	
	Server(const UInt16& port, const int& bufferSize) {
		socket = SocketAddress(port);
		this->bufferSize = bufferSize;
	}
	
	void receiveMessages() {
		
		DatagramSocket datagram(socket);

		char buffer[bufferSize];
		
		cout << "Server started\n" << endl;
		
		while (!datagram.available()) {
			
			SocketAddress sender;
			
			int size = datagram.receiveFrom(buffer, bufferSize, sender);
			buffer[size] = '\0';
			
			cout << (debugModeEnabled ? (sender.toString() + ": ") : "- ") << buffer << endl;
			
			if (string(buffer) == "\\end") {
				cerr << "\nUser: " << sender.toString() << " ended connection" << endl;
				datagram.close(); // Closes the server
			}
		}
	}
};

bool Server::debugModeEnabled = false;
