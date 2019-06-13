#include <algorithm>
#include <iostream>

using namespace std;

void swap_family() {
	cout << "--- swap ----" << endl;
	int a = 3;
	int b = 5;

	cout << "before swap a: " << a << ", b: " << b << endl;
	swap(a, b);
	cout << "after swap a: " << a << ", b: " << b << endl;

	cout << "--- swap_ranges() ----" << endl;
	int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int arr2[] = {6, 7, 8, 9, 10};
	cout << "before arr1 : ";
	for (const auto& v : arr1) {
		cout << v << ' ';
	}
	cout << endl;
	cout << "before arr2 : ";
	for (const auto& v : arr2) {
		cout << v << ' ';
	}
	cout << endl;

	swap_ranges(arr1, arr1 + 5, arr2);
	// FIXME: size is larger then crash
	// swap_ranges(arr1, arr1 + 7, arr2);

	cout << "after swap_ranges(arr1, arr1 + 3, arr2)" << endl;
	cout << "after arr1 : ";
	for (const auto& v : arr1) {
		cout << v << ' ';
	}
	cout << endl;
	cout << "after swap_ranges arr2 : ";
	for (const auto& v : arr2) {
		cout << v << ' ';
	}
	cout << endl;

	cout << "--- copy() ----" << endl;
	copy(arr1 + 1, arr1 + 4, arr2 + 1);
	cout << "after   copy (arr1 + 1, arr1 + 4, arr2 + 1)" << endl;
	cout << "after copy arr1 : ";
	for (const auto& v : arr1) {
		cout << v << ' ';
	}
	cout << endl;
	cout << "after copy arr2 : ";
	for (const auto& v : arr2) {
		cout << v << ' ';
	}
	cout << endl;

	cout << "--- fill() ----" << endl;
	fill(arr1 + 1, arr1 + 4, 3);
	cout << "after fill(arr1 + 1, arr1 + 4, 3) arr1 : ";
	for (const auto& v : arr1) {
		cout << v << ' ';
	}
	cout << endl;
	fill(arr2 + 3, arr2 + 4, 1);
	cout << "after fill(arr2 + 3, arr1 + 4, 1) arr2 : ";
	for (const auto& v : arr2) {
		cout << v << ' ';
	}
	cout << endl;
}