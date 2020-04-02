#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

using iterType = vector<int>::iterator;

iterType bin_find(iterType first, iterType last, int value) {
	iterType lower = lower_bound(first, last, value);

	if (lower == last) {
		return last;
	}
	if (value == *lower) {
		return lower;
	} else {
		return last;
	}
}

void bound_test() {
	vector<int> data = {1, 2, 4, 6, 9, 10};

	// auto it = lower_bound(begin(data), end(data), 3);
	auto it = bin_find(begin(data), end(data), 9);
	if (it != end(data)) {
		cout << *it << " found at index " << distance(begin(data), it) << endl;
	} else {
		cout << "not found" << endl;
	}

	set<int> s{17, 25, 67, 84, 90, 30, 55, 6, 9, 28, 96};
	set<int>::iterator setIter;

	setIter = lower_bound(s.begin(), s.end(), 90);
	cout << "lower bound 90: ";
	if (setIter != s.end())
		cout << *setIter << endl;
	else
		cout << "NOT FOUND" << endl;

	setIter = upper_bound(s.begin(), s.end(), 90);
	cout << "upper bound 90: ";
	if (setIter != s.end())
		cout << *setIter << endl;
	else
		cout << "NOT FOUND" << endl;

	setIter = s.lower_bound(90);
	cout << "lower bound 90: ";
	if (setIter != s.end())
		cout << *setIter << endl;
	else
		cout << "NOT FOUND" << endl;

	setIter = s.upper_bound(90);
	cout << "upper bound 90: ";
	if (setIter != s.end())
		cout << *setIter << endl;
	else
		cout << "NOT FOUND" << endl;
}