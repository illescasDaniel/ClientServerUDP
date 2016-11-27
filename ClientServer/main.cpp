#include "Poco/Net/DatagramSocket.h"
#include "Poco/Net/SocketAddress.h"

#include <string>
#include <thread>
#include "Client.hpp"
#include "Server.hpp"

int main(int argc, char* argv[]) {
	
	// Default values
	IPAddress IP ("127.0.0.1");
	UInt16 port = 10000;
	int bufferSize = 1024;
	
	for (int i = 1; i < argc; ++i) {
		if (i + 1 <= argc) {
			if (string(argv[i]) == "--ip") { IP = IPAddress(argv[i+1]); }
			if (string(argv[i]) == "--port") { port = atoi(argv[i+1]); }
			if (string(argv[i]) == "--size") { bufferSize = atoi(argv[i+1]); }
		}
	}
	
	Client daniel(IP, port);
	Server myServer(IP, port, bufferSize);
	
	thread clientThread(daniel.sendMessageThread());
	thread serverThread(myServer.receiveMessagesThread());
	
	clientThread.join();
	serverThread.join();
}
