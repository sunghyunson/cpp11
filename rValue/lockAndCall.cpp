#include <functional>
#include <iostream>

using namespace std;

void foo(int n) { cout << "foo " << n << endl; }
void goo(int& n) {
	cout << "goo " << n << endl;
	n = 0;
}

template <typename F, typename A>
void lockAndCall(F f, A& a) {
	// TODO - synchronization
	f(a);
}

template <typename F, typename A>
void lockAndCall(F f, const A& a) {
	// TODO - synchronization
	f(a);
}

template <typename T>
class my_reference_wrapper {
public:
	my_reference_wrapper(T& obj) : pObj(&obj) {}

	operator T&() { return *pObj; }

private:
	T* pObj;
};

template <typename T>
my_reference_wrapper<T> my_ref(T& p) {
	return my_reference_wrapper<T>(p);
}

void zar(int a, int& b) {
	a = 0;
	b = 0;
}

int main() {
	int x = 10;

	lockAndCall(foo, x);
	lockAndCall(goo, x);
	lockAndCall(foo, 10);

	cout << x << endl;

	int n1 = 10;
	int n2 = 20;

	my_reference_wrapper<int> r1(n1);
	my_reference_wrapper<int> r2(n2);

	int n3 = r1; // << my_reference_wrapper<int> -> int& implicite conversion
	r1 = r2;
	n2 = 30;

	cout << n1 << ", " << n2 << ", " << r1 << ", " << r2 << ", " << n3 << endl;

	int xx = 10;
	int yy = 10;
	function<void()> f;

	f = bind(&zar, ref(xx), ref(yy));
	f();
	cout << xx << endl;
	cout << yy << endl;

	return 0;
}
