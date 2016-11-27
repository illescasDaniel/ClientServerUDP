#pragma once

#include <iostream>
#include <string>

using namespace std;
using namespace Poco;
using namespace Poco::Net;

struct Client {
	
	SocketAddress socket;
	
	// By default the client connects to itself {remove}?
	Client() { socket = SocketAddress("127.0.0.1", 10000); } // SocketAddress("127.0.0.1", 10000);
	
	Client(const IPAddress& IP, const UInt16& port) {
		socket = SocketAddress(IP, port);
	}
	
	void sendMessages() {
		
		DatagramSocket datagram;
		datagram.connect(socket);
		string message;
		
		while (!datagram.available()) {
		
			getline(cin, message);
			
			datagram.sendBytes(message.data(), int(message.size()));
			
			if (message == "\\end") {
				datagram.close();
			}
		}
	}
	
	string IP() {
		return socket.host().toString();
	}

	UInt16 port() {
		return socket.port();
	}
	
	static void sendMessage(const IPAddress& IP, const UInt16& port, const string& message) {
		SocketAddress socket(IP, port);
		DatagramSocket datagram;
		datagram.connect(socket);
		datagram.sendBytes(message.data(), int(message.size()));
	}
};
