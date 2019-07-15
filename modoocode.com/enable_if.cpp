#include <type_traits>
#include <iostream>

using namespace std;

// ITEM1: enable_if 가 반환값으로 사용된 경우
template <typename T>
enable_if_t<is_integral<T>::value, T> foo1(T t)
{
	cout << "foo1: 정수형" << endl;
	return t;
}

template <typename T>
typename enable_if<is_floating_point<T>::value, T>::type foo1(T t)
{
	cout << "foo2: 실수형" << endl;
	return t;
}

// ITEM2: enable_if가 함수 인자로 사용된 경우
/*
int foo2(int num, void* = 0)
{
	cout << "foo2: " << num << endl;
	return num;
}
*/

template <typename T>
T foo2(T t, typename enable_if<is_integral<T>::value, T>::type = 0)
{
	cout << "foo2: " << t << endl;
	return t;
}

// ITEM3: enable_if가 함수 template 인자로 사용된 경우
template <typename T, typename = typename enable_if<is_integral<T>::value, T>::type>
T foo3(T t)
{
	cout << "foo3: " << t << endl;
	return t;
}



// ITEM4: enable_if가 클래스 템플릿 인자로 사용된 경우
template <typename T, typename Enable = void>
class A; // undefined

template <typename T>
// // class A<T, typename enable_if<is_floating_point<T>::value, T>::type>
class A<T, typename enable_if<is_integral<T>::value, T>::type>
// class A<T, typename enable_if_t<is_integral_v<T> > >
{
public:
	A()
	{
		cout << "CTR" << endl;
	}
};


template <typename To, typename From>
To convert(From f)
{
	static int num = 0;
	num++;
	cout << "num: " << num << " From: " << f << endl;
	return 4.44;
}

int main()
{
	foo1(1);
	foo1(1.23);

	foo2(3);
	// foo2(1.23);

	foo3(2);

	A<int, int> a1; //BAD compile error
	// A<double> a2;

	double d = 3.33;
	int i = convert<int, int>(d);
	cout << i << endl;
	char j = convert<char>(d);
	cout << j << endl;
	int k = convert<int>(d);
	cout << k << endl;
	int l = convert<int>(d);
	cout << l << endl;

	int a = 20;
	int b = 30;

	auto fff = [&a, &b]() { return a + b; };
	cout << fff() << endl;

	a = 30;
	b = 50;
	cout << fff() << endl;

	return 0;
}