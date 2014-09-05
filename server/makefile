
simple_server_objects = ServerSocket.o Socket.o server_main.o

all : simple_server

simple_server: $(simple_server_objects)
	g++ -o simple_server $(simple_server_objects)


Socket: Socket.cpp
ServerSocket: ServerSocket.cpp
simple_server_main: server_main.cpp


clean:
	rm -f *.o simple_server
