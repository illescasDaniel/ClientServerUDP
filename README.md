# Client Server UDP

Simple UDP client-server program using POCO C++ libraries (https://pocoproject.org)


Client struct
-----
```c++

struct Client {

	SocketAddress socket;

	Client() { socket = SocketAddress("127.0.0.1", 10000); }

	Client(const IPAddress& IP, const UInt16& port) { /* ... */ }

	// Receive user input and send it to the server
	void sendMessages() { /* ... */ }

	// Send a message to a server
	static void sendMessage(const IPAddress& IP, const UInt16& port, const string& message) { /* ... */}
};

```

Server struct
-----
```c++

struct Server {

	int bufferSize;
	SocketAddress socket;
	static bool debugModeEnabled;

	Server(): bufferSize(1024) { socket = SocketAddress(10000); }

	Server(const UInt16& port, const int& bufferSize) { /* ... */ }

	// Display messages sent by user/s
	void receiveMessages() { /* ... */ }
};

```

How to compile
-----

1 - Install POCO libraries from [here](https://pocoproject.org/download/index.html) or using [brew](http://brew.sh) with this command:  
```
brew install poco
```

2 - Use the included [makefile](https://github.com/illescasDaniel/ClientServer/blob/master/ClientServer/makefile) or run this command:  
```bash
g++ -std=c++1z main.cpp -I /usr/local/include -I . -L /usr/local/lib -lPocoNet -lPocoFoundation -Wno-deprecated
```

How to run
----
After the program is compiled you can use these program arguments:

**-ip** `<ip address>`  
**-port** `<port number>`  
**-size** `<buffer size>`  
**--debug** (enables the debug mode)
