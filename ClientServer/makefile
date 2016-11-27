## FLAGS ##
Libraries = -L /usr/local/lib -lPocoNet -lPocoFoundation
Headers = -I /usr/local/include -I .
Sources = main.cpp $(Headers) $(Libraries)
CompilerFlags = -O3 -Wno-deprecated
OutputName = ClientServer

## TARGETS ##
all: 
	@g++ -std=c++1z $(CompilerFlags) $(Sources) -o $(OutputName)

clean:
	@rm $(OutputName)*
