all : clean server client
run : clean client server

server:
	g++ -o server -std=c++17 server.cpp -lpthread
client:
	g++ -o client -std=c++17 client.cpp -lpthread
clean:
	rm -rf server client