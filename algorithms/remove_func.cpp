#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

bool isOdd(int n) { return (n % 2 == 1); }

void remove_func() {
	// int aa[] = {1, 3, 2, 4, 5, 2, 4, 2, 8, 6};
	// int bb[10];
	array<int, 11> a{1, 7, 3, 2, 4, 5, 2, 4, 2, 8, 6};
	array<int, 11> b;
	// b.swap(a);
	copy(begin(a), end(a), begin(b));

	cout << "a: ";
	for (const auto& value : a) {
		cout << value << ' ';
	}
	cout << endl;

	cout << "b: ";
	for (const auto& value : b) {
		cout << value << ' ';
	}
	cout << endl;

	array<int, 10>::iterator p;
	array<int, 10>::iterator q;

	p = remove(begin(a), end(a), 2);
	q = remove_if(begin(b), end(b), isOdd);

	cout << "p: " << *p << endl;
	cout << "q: " << *q << endl;

	cout << "a: ";
	for (const auto& value : a) {
		cout << value << ' ';
	}
	cout << endl;

	cout << "b: ";
	for (const auto& value : b) {
		cout << value << ' ';
	}
	cout << endl;

	for (auto i = begin(a); i < p; ++i) {
		cout << *i << ' ';
	}
	cout << endl;
	for (auto i = begin(b); i < q; ++i) {
		cout << *i << ' ';
	}
	cout << endl;
}