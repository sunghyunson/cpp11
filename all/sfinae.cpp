#include <algorithm>
#include <iostream>
#include <type_traits>

using namespace std;

template <typename T>
using IsNotReference = typename std::enable_if<std::is_integral<T>::value>::type;

template <typename T>
class MyClass {
public:
	// void f(T const& x) { cout << "const f: " << x << endl; }

	// template <typename T_ = T>
	// void f(T&& x, typename std::enable_if<!std::is_reference<T_>::value, std::nullptr_t>::type = nullptr) {
	// 	cout << "ok f " << endl;
	// }
	// template<typename T_ = T, typename = IsNotReference<T_>>
	template<typename T_ = T, IsNotReference<T_> = 0>
	void f(T& x) {cout << "T& f: " << x << endl;}
};

template<typename T>
class TypeError;

int main() {
	int a = 3;
	int& ra = a;
	MyClass<int> test;

	// TypeError<decltype(ra)> ttt;
	// TypeError<decltype(a)> ttt2;

	// test.f(32);
	// test.f(a);
	// test.f(ra);
	// test.f<float>(34.3);
}
