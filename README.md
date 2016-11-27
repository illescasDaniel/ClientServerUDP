# Client Server UDP

Simple UDP client-server program using POCO C++ libraries (https://pocoproject.org)


Client struct
-----
```c++

struct Client {

	IPAddress IP;
	UInt16 port;

	Client(): IP("127.0.0.1"), port(10000) { }

	Client(const IPAddress& IP, const UInt16& port) { /* ... */ }

	// Receive user input and send it to the server
	void sendMessage() { /* ... */ }

	// Send a message to a server
	static void sendMessage(const IPAddress& IP, const UInt16& port, const string& message) { /* ... */}
};

```

Server struct
-----
```c++

struct Server {

	IPAddress IP;
	UInt16 port;
	int bufferSize;

	static bool debugModeEnabled;

	Server(): IP("127.0.0.1"), port(10000), bufferSize(1024) { }

	Server(const IPAddress& IP, const UInt16& port, const int& bufferSize) { /* ... */ }

	// Display messages sent by user/s
	void receiveMessages() { /* ... */ }
};

```

How to compile
-----

Use the included [makefile](https://github.com/illescasDaniel/ClientServer/blob/master/ClientServer/makefile) or run this command:
```bash
g++ -std=c++1z main.cpp -I /usr/local/include -lPocoNet -lPocoFoundation -L /usr/local/lib
```

How to run
----
After the program is compiled you can use these program arguments:

**-ip** `<ip address>`  
**-port** `<port number>`  
**-size** `<buffer size>`  
**--debug** (enables the debug mode)
