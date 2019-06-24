#include <iostream>

using namespace std;

class Test;

void foo(Test* p) { delete p; }

class Test {
public:
	Test() { cout << "Test CTR" << endl; }
	~Test() { cout << "~Test DTR" << endl; }
};

int main() {
	Test* pt = new Test;
	foo(pt); // << 소멸자가 호출 되지 않음
	// delete pt;
	return 0;
}