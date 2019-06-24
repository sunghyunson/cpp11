#include <functional>
#include <iostream>
#include <memory.h>
#include <type_traits>

using namespace std;

int f(int a) { return a + 1; }

template <typename... Types>
void foo(Types... args) {
	cout << "foo" << endl;
}

template <typename... Types>
void goo(Types... args) {
	cout << "goo" << endl;
}

void hoo(int a, int b, int c) { cout << "hoo " << a << b << c << endl; }

template <typename... Types>
void bar(Types... args) {
	cout << "sizeof...(Types): " << sizeof...(Types) << endl;
	cout << "sizeof...(args): " << sizeof...(args) << endl;

	goo(args...);

	hoo(args...);
}


void zar() { cout << "end of zar" << endl; }

template <typename T, typename... Types>
void zar(T a, Types... args) {
	static int n = 0;
	n++;

	cout << n << " Zar current: " << typeid(T).name() << " : " << a << endl;

	zar(args...);
}

int main() {
	foo(1, 3.4, "a");
	bar(1, 2, 3);
	zar(1, 3.4, "aa", 5);
	return 0;
}
