#include <algorithm>
#include <array>
#include <iostream>

using namespace std;


constexpr int factorial2(int n);
long ffunc(int n);

template <int n>
struct constN {
	constN() { cout << n << endl; }
};


constexpr long ffuncConst(int n) {
	long result = 0;
	if (n <= 1) {
		result = 1;
	} else {
		result = ffuncConst(n - 1) + ffuncConst(n - 2) - ffuncConst(n - 3) + ffuncConst(n - 4);
	}
	return result;
}

constexpr int factorial(int n) {
	// no local variable
	// only one return
	return n <= 1 ? 1 : (n * factorial(n - 1));
}


int main() {
	cout << "constexpr and const" << endl;
	constN<5> gg;
	constN<ffuncConst(35)> out1;

	// TODO: 1 usage of variable
	constexpr float x = 42.f;
	constexpr float y{108.f};
	// constexpr int i; //FIXME: error
	int j = 0;
	// constexpr int k = j + 1; //FIXME: error

	// cout << factorial(15) << endl;
	// cout << factorial2(15) << endl;
	cout << ffunc(3) << endl;
	// cout << ffuncConst(35) << endl;

	std::vector<int> vv{5, 13, 7, 8, 9, 2, 4, 1, 5, 9};
	std::nth_element(vv.begin(), begin(vv) + 3, vv.end());
	for (const auto& v : vv) {
		cout << v << ' ';
	}
	cout << endl;

	const int arraySize = 5;
	array<int, arraySize> tmp;

	std::vector<int>::value_type k = j;
	cout << k << endl;


	return 0;
}

long ffunc(int n) {
	long result = 0;
	if (n <= 1) {
		result = 1;
	} else {
		result = ffunc(n - 1) - ffunc(n - 2);
	}
	return result;
}



constexpr int factorial2(int n) {
	int result = 0;

	if (n <= 1) {
		result = 1;
	} else {
		result = 3;
	}
	return result;
}