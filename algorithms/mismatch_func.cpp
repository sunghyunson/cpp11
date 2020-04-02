#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

using namespace std;

void mismatch_func() {
	vector<int> a{1, 1, 2, 3, 3, 3, 3, 3, 7, 5, 4, 8, 6, 6};
	vector<int> b{1, 2, 3, 3, 5, 5, 7, 1, 6, 4};

	cout << "size of a: " << a.size() << endl;
	// unique(begin(a), end(a));
	// cout << "after uniqe size of a: " << a.size() << endl;
	a.erase(unique(begin(a), end(a)), end(a));
	cout << "after erase(uniqe) size of a: " << a.size() << endl;
	for (auto val : a) {
		cout << val << ' ';
	}
	cout << endl;

	cout << "point of mismatch..." << endl;

	// pair<int*, int*> result;
	// auto p = begin(a);
	// auto q = begin(b);
	// while (true) {
	// 	auto result = mismatch(p, end(a), q);
	// 	p = result.first;
	// 	q = result.second;
	// 	if (p == end(a)) {
	// 		break;
	// 	}

	// 	cout << "point of a'distance: " << distance(begin(a), p) << " a: " << *p << " b: " << *q << endl;
	// 	p++;
	// 	q++;
	// }
}