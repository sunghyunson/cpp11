#include <iostream>
#include <functional>

using namespace std;

struct S
{
	int data;
	S(int d) : data(d)
	{
		cout << "Normal CTR" << endl;
	}
	S(const S& other)
	{
		cout << "COPY CTR" << endl;
	}
	S(S&& other)
	{
		cout << "MOVE CTR" << endl;
	}
};

void do_something(S& s1, const S& s2)
{
	s1.data = s2.data + 3;
}

int main()
{
	S s1(1), s2(2);

	cout << "Before: " << s1.data << endl;

	// ITEM s1's copy value transfered
	// auto do_something_with_s1 = std::bind(do_something, s1, placeholders::_1);
	auto do_something_with_s1 = std::bind(do_something, ref(s1), placeholders::_1);
	do_something_with_s1(s2);

	cout << "After: " << s1.data << endl;
}