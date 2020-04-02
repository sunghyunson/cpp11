run :
	g++ -fPIC -c mymodule1.cc
	g++ -shared -fPIC -o libmymodule.so mymodule1.o
	g++ -o main main.cc  -std=c++17 -L. -ldl -lmymodule
