#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

void print_separator(string str) { cout << "------" << str.c_str() << "------\n"; }

void trait_is_void() {
	cout << boolalpha;
	cout << is_void<void>::value << '\n';
	cout << is_void<int>::value << '\n';
	cout << noboolalpha;
}

template <class T>
T f(T i) {
	static_assert(is_integral<T>::value, "Integral required.");
	cout << i << endl;
	return 1;
}

void trait_is_nullptr() {
	cout << is_null_pointer<decltype(nullptr)>() << ' ' << is_null_pointer<int*>::value << '\n'
		 << is_pointer<decltype(nullptr)>::value << ' ' << is_pointer<int*>::value << '\n';
}

void trait_is_integral() {
	int a = 3;
	cout << is_integral<float>::value << '\n';
	cout << is_integral<bool>::value << '\n';
	cout << is_integral<decltype(a)>::value << '\n';
	// cout << is_integral<a>::value << '\n'; // error
}

int* func(int* a, int* b) {
	cout << *a << endl;
	cout << *b << endl;
	return a;
}

class dummy {
public:
	dummy();

private:
	void ppp();
};

void trait_is_same() {
	cout << boolalpha;
	cout << "is_same<int, int32_t>() " << is_same<int, int32_t>() << '\n';
	cout << "is_same<int, int64_t>() " << is_same<int, int64_t>() << '\n';
}

extern void forTrait();

int main() {
	cout << "trait " << endl;
	// print_separator("is_void");
	// trait_is_void();
	// print_separator("is_nullptr");
	// trait_is_nullptr();
	// print_separator("is_integral");
	// trait_is_integral();
	// print_separator("is_same");
	// trait_is_same();

	forTrait();
	return 0;
}