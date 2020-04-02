#include <iostream>
#include <string>
#include <type_traits>

using namespace std;


template <typename T>
struct IsArray {
	enum { kValue = false };
	enum { kSize = -1 };
};

template <typename T, int N>
struct IsArray<T[N]> {
	enum { kValue = true };
	enum { kSize = N };
};

template <typename T>
void bar(const T& a) {
	if (IsArray<T>::kValue) {
		cout << "This array. size is " << IsArray<T>::kSize << endl;
	} else {
		cout << "NOT array" << endl;
	}
}


template <typename T>
struct IsPointer {
	enum { kValue = false };
};

template <typename T>
struct IsPointer<T*> {
	enum { kValue = true };
};

template <typename T>
void foo(const T& a) {
	if (IsPointer<T>::kValue) {
		cout << "T -> pointer" << endl;
	} else {
		cout << "T -> NOT poitner" << endl;
	}
}

template <int N>
struct Int2Type {
	enum { value = N };
};

template <typename T>
T MaxImpl(T a, T b, Int2Type<1>) {
	return *a < *b ? b : a;
}

template <typename T>
T MaxImpl(T a, T b, Int2Type<0>) {
	return a < b ? b : a;
}

template <typename T>
T Max(T a, T b) {
	return MaxImpl(a, b, Int2Type<IsPointer<T>::kValue>());
	// if (IsPointer<T>::kValue) {
	// 	cout << "Poitner";
	// 	return *a < *b ? b : a;
	// } else {
	// 	cout << "NOT pointer";
	// 	return a < b ? b : a;
	// }
}

void forTrait() {
	int a = 0;
	int b[10]{0};

	bar(a);
	bar(b);

	int n = 0;
	foo(n);
	foo(&n);

	int i = 0;
	int j = 1;
	cout << Max(i, j) << endl;
	cout << *Max(&i, &j) << endl;

	return;
}