#include <functional>
#include <iostream>
#include <memory.h>
#include <type_traits>

using namespace std;

class A {
public:
	static int aaa;
	static void print() { cout << A::aaa << endl; }
	class B {
	public:
		B() {
			cout << "B ctr" << endl;
			A::aaa = 20;
		}
	};

	static B bbb;
};

class Point {
public:
	int x, y;

public:
	Point(int a, int b) : x(a), y(b) { cout << "Point CTR " << endl; }
	Point(const Point& lhs) { cout << "Point Copy-CTR" << endl; }
};

class Line {
public:
	Line() {}
	void show() { cout << left->x << endl; }

private:
	Point* left;
};

template <typename T>
void foo(T p) {
	T temp;
}

template <typename T>
void goo(T tmp) {
	static_assert(is_pod<T>::value, "goo : Not POD");
	memset(&tmp, 0, sizeof(T));
}

// int A::aaa;
// A::B A::bbb;

void koo(int a, int b, int c, int d) { cout << a << b << c << d << endl; }

int main() {
	// A::B bb;
	// cout << "hi" << endl;
	// A::print();
	function<void(int, int)> f;
	f = bind(&koo, 8, placeholders::_2, placeholders::_1, 1);
	f(5, 3);

	Point point(3, 4);
	Line line;
	line.show();
	// foo(point);
	// goo(point);
}