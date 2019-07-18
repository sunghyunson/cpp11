#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class A {
	int z = 33;
	int x = 11;

public:
	void foo() { cout << "A foo " << x << endl; }
};

class B {
	int y = 2;
	int a = 1;
	int c = 3;

public:
	void goo() { cout << "B goo " << c << endl; }
};

int main() {
	A aaa;
	B* p = reinterpret_cast<B*>(&aaa);
	p->goo();
	return 0;
}
