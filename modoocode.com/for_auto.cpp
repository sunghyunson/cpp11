#include <iostream>
#include <functional>
#include <memory>

using namespace std;

struct Widget
{
};

int main()
{
	int a = 3;
	int b = 4;
	int c = 5;
	// auto my_function = [](const unique_ptr<Widget>& p1, const unique_ptr<Widget>& p2) { return *p1 < *p2; };
	auto my_function1 = [](const int* p1, const int* p2) { return *p1 < *p2; };
	auto my_function2 = [](auto p1, auto p2) { return *p1 < *p2; };
	cout << my_function1(&a, &b) << endl;
	cout << my_function2(&c, &b) << endl;

	float aa = 3.14;
	float bb = 4.33;
	cout << my_function2(&aa, &bb) << endl;
	return 0;
}