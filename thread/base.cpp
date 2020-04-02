#include <functional>
#include <thread>
#include <iostream>

using namespace std;

// ITEM function
void threadFunc(int val)
{
	cout << val << endl;
}

// ITEM functor & class function
class MyPrint
{
public:
	MyPrint(const string& text)
	{
		m_myword = text;
	}
	void operator()(const string& text) const
	{
		cout << m_myword << endl;
		cout << text << endl;
	}
	void printFunction() const
	{
		cout << m_myword << endl;
	}

private:
	string m_myword;
};

template <typename T> class TypeNameTester;

int main()
{
	thread th1(threadFunc, 100);
	th1.join();

	auto th2 = thread(MyPrint("Hello, World"), "Bye, World");
	th2.join();

	MyPrint printing("C+11 thread");
	thread th3(thread(&MyPrint::printFunction, printing));
	th3.join();

	thread th4(thread(printing, "for test"));
	th4.join();

	auto aa = [](int a, int b) { return a + b; };
	function<int(int, int)> bb = [](int a, int b) { return a + b; };

	TypeNameTester<decltype(aa)> gogo;

	return 0;
}