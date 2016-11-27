## FLAGS ##
Libraries = -lPocoNet -L /usr/local/lib
Headers = -I /usr/local/include
Sources = main.cpp $(Headers) $(Libraries)
CompilerFlags = -Os -Wno-deprecated
OutputName = ClientServer

## TARGETS ##
all: 
	@g++ -std=c++1z $(CompilerFlags) $(Sources) -o $(OutputName)

clean:
	@rm $(OutputName)*
