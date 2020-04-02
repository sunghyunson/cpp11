#include <algorithm>
#include <iostream>

using namespace std;

void min_max() {
	int m = 3;
	int n = 7;
	cout << "max : " << max(m, n) << endl;
	cout << "min : " << min(m, n) << endl;

	cout << "--- min_max ---" << endl;
	int aar[] = {1, 3, 7, 2, 5, 4, 3};
	cout << "max value: " << *max_element(begin(aar), end(aar)) << endl;
	cout << "max address: " << max_element(begin(aar), end(aar)) << endl;
	cout << "max value: " << *min_element(begin(aar), end(aar)) << endl;
	cout << "max address: " << min_element(begin(aar), end(aar)) << endl;

	cout << "--- min_element max_element ---" << endl;
	string str = "test_of_algorithm";
	cout << str << endl;
	cout << "string min_element : " << *min_element(str.begin(), str.end()) << endl;
	cout << "string max_element : " << *max_element(str.begin(), str.end()) << endl;
	cout << "string min_element : " << *min_element(begin(str), end(str)) << endl;
	cout << "string max_element : " << *max_element(begin(str), end(str)) << endl;
}

