# Client Server C++

Simple Client-server program using POCO C++ libraries (https://pocoproject.org)


Client class
-----
```c++

class Client {

	IPAddress IP;
	UInt16 port;

public:

	Client(): IP("127.0.0.1"), port(10000) { }

	Client(const IPAddress& IP, const UInt16& port) { /* ... */ }

	// Receive user input and send it to the server
	void sendMessage() const { /* ... */ }

	// Run the above method on a thread
	thread sendMessageThread() { /* ... */ }
};

```

Server class
-----
```c++

class Server {

	IPAddress IP;
	UInt16 port;
	int bufferSize;

public:

	Server(): IP("127.0.0.1"), port(10000), bufferSize(1024) { }

	Server(const IPAddress& IP, const UInt16& port, const int& bufferSize) { /* ... */ }

	// Display messages sent by user/s
	void receiveMessages() const { /* ... */ }

	// Run the above method on a thread
	thread receiveMessagesThread() { /* ... */ }
};

```


How to use
------

```c++

// Run client
Client daniel(IP, port);
thread clientThread(daniel.sendMessageThread());

// Run Server
Server myServer(IP, port, bufferSize);
thread serverThread(myServer.receiveMessagesThread());

// Join threads
clientThread.join();
serverThread.join();

```

How to compile
-----

Use the included [makefile](https://github.com/illescasDaniel/ClientServer/blob/master/ClientServer/makefile) or run this command:
```bash
g++ -std=c++1z main.cpp -I /usr/local/include -lPocoNet -L /usr/local/lib
```
