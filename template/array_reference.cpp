#include <iostream>
#include <typeinfo>

using namespace std;

int func(int a)
{
	cout << "func called with " << a << endl;
	return 0;
}

int main()
{
	int v = 0;
	int n = v;
	int& r = v;
	int* p = &v;

	int x[10] = {
		0,
	};
	// BAD 배열은 자신과 동일한 타입의 객체로 초기화 할 수 없다.
	// int y[10] = x;

	int(&r2)[10] = x; // GOOD 배열을 가리키는 참조
	int(*p2)[10] = &x; // &x : int[10]을 가리키는 포인터 변수

	int* p3 = x;

	cout << p2 << endl; // 배열의 주소
	cout << p3 << endl; // 배열의 첫번째 요소의 주소...

	cout << "p2{int(*p2)[10]}(40) + 1: " << p2 + 1 << endl;
	cout << "p3(sizeof(int) : 4) + 1: " << p3 + 1 << endl;

	int (&ref_func)(int) = func;
	ref_func(3);

	int (*point_func)(int) = func;
	point_func(4);

	return 0;
}