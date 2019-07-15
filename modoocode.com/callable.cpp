#include <functional>
#include <iostream>


using namespace std;

int some_func(const string& a)
{
	cout << "Func1 호출 " << a << endl;
	return 0;
}

struct S
{
	void operator()(int a, int b)
	{
		cout << "a + b = " << a + b << endl;
	}
};

class A
{
	int c;

public:
	A(int c) : c(c)
	{
	}
	int some_func()
	{
		cout << "비상수 함수: " << ++c << endl;
	}
	// int some_func() const
	// {
	// 	cout << "상수 -_-" << endl;
	// }
	int some_const_func() const
	{
		cout << "상수 함수: " << c << endl;
	}
};


int main()
{
	S some_obj;
	some_obj(3, 4);

	auto fauto = [](int a, int b) { cout << "a + b = " << a + b << endl; };
	fauto(3, 4);

	function<int(const string& s)> f1 = some_func;
	f1("good morning");
	function<void(int, int)> f2 = S();
	f2(3, 5);
	function<void()> f3 = []() { cout << "Func3 호출" << endl; };
	f3();


	A a(5);
	a.some_func();
	std::function<int(A&)> ff1 = &A::some_func;
	std::function<int(const A&)> ff2 = &A::some_const_func;
	ff1(a);
	ff2(a);
}