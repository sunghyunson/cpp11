#include <iostream>
#include <thread>

using namespace std;

extern void min_max();
extern void swap_family();
extern void reverse_rotate();
extern void find_family();
extern void remove_func();
extern void mismatch_func();
extern void bound_test();

int main() {
	cout << "==============Algorithms================" << endl;
	cout << "============== min_max ================" << endl;
	min_max();

	cout << "============== swap_family ================" << endl;
	swap_family();

	cout << "============== reverse rotate ================" << endl;
	reverse_rotate();

	cout << "============== find_else ================" << endl;
	find_family();

	cout << "============== remove funcs ================" << endl;
	remove_func();

	cout << "============== mismatch funcs ================" << endl;
	mismatch_func();

	cout << "============== bound_test ================" << endl;
	bound_test();

	return 0;
}