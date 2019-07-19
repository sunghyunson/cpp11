#include <functional>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <chrono>

using namespace std;

int get2()
{
	return 2;
}

int get3()
{
	return 3;
}

int dummy(int a, int b)
{
	a = 3;
	b = 5;
	return 3;
}

int calc(int a, int b, int c)
{
	return (a + b) * c;
}

template <typename T>
class DUMMY;

// NOTE
//template<typename T>
//const T& min(const T& a, const T& b);

int main()
{
	auto curCalc = bind(calc, 5, placeholders::_4, placeholders::_8);
	cout << "calc: " << curCalc(1, 2, 3, 4, 5, 6, 7, 8, 9) << endl;
	using dddtype = int (*)(int, int);
	auto dummy3 = std::bind(dummy, 5, 3);
	// DUMMY<decltype(dummy3)> dm;
	cout << dummy3() << endl;
	const int& minValue = min(get2(), get3());
	cout << minValue << '\n'; // undefined behavior
	return 0;
}