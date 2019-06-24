#include <iostream>

using namespace std;

extern void array_test();
extern void vector_test();
extern void vector_alloc();
extern void forword_test();
extern void settest();

void print_separator(string str) { cout << "------" << str.c_str() << "------\n"; }

class Base {
public:
	virtual void func1() { cout << "virtual base f1" << endl; }
	virtual void func2() { cout << "virtual base f2" << endl; }
	void func3() { cout << "no virtual base f3" << endl; }
};

class Derived : public Base {
public:
	virtual void func1() { cout << "virtual derive f1" << endl; }
	void func4() { cout << "no virtual derive f4" << endl; }
};

int main() {
	cout << "containers" << endl;
	print_separator("Sequence Containers");
	print_separator("1. Array from c++11");
	array_test();
	print_separator("vecotr");
	vector_test();
	vector_alloc();
	forword_test();

	int g = 3;
	const int& good = g;
	cout << "reference : " << good << endl;

	Derived derive;
	derive.func1();
	derive.func3();

	string aa = "aa";
	string bb = "bb";
	string name1 = aa;
	cout << name1.c_str() << endl;
	name1 = bb;
	cout << name1.c_str() << endl;

	string const name2 = bb;
	cout << name2.c_str() << endl;
	// name2[0] = 'z';
	cout << name2[0] << endl;

	string name3 = aa;
	name3[0] = 'z';
	cout << name3 << endl;

	settest();
}
