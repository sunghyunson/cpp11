#include <iostream>

using namespace std;

// NOTE 1
// ITEM primary template
// ITEM partial specialization
// ITEM specialization

// NOTE 2
// NOTE 3

template <typename T, int N = 10>
class DefN
{
public:
	void show()
	{
		cout << "N: " << N << endl;
	}
	T buff[N];
};

// 부분전문화: default parameter는 표기하지 않는다.
template <typename T, int N>
class DefN<T*, N>
{
	T buff[N];

public:
	void show()
	{
		cout << "N: " << N << endl;
	}
};

// primary template
template <typename T>
class stack
{
public:
	void push(T a)
	{
		cout << "T: " << a << endl;
	}
};

// partial specialization
template <typename T>
class stack<T*>
{
public:
	void push(T* a)
	{
		cout << "T*: " << *a << endl;
	}
};

// specailization
template <>
class stack<char*>
{
public:
	void push(char* a)
	{
		cout << "char*: " << *a << endl;
	}
};

int main()
{
	stack<int> s1;
	s1.push(2);

	int val = 5;
	stack<int*> s2;
	s2.push(&val);

	stack<char*> s3;
	char cc = 'a';
	s3.push(&cc);

	// NOTE3
	DefN<int> def1;
	def1.show();
	DefN<int, 7> def2;
	def2.show();
	DefN<int*, 7> def3;
	def3.show();

	return 0;
}