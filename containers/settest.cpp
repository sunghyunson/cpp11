#include <algorithm>
#include <iostream>
#include <set>

using namespace std;

template <typename BidirIt>
bool next_permu(BidirIt first, BidirIt last) {
	if (first == last)
		return false;
	BidirIt i = last;
	if (first == --i) {
		return false;
	}

	while (true) {
		BidirIt i1, i2;

		i1 = i;
		if (*--i < *i1) {
			i2 = last;
			while (!(*i < *--i2)) {
				;
			}
			iter_swap(i, i2);
			reverse(i1, last);
			return true;
		}
		if (i == first) {
			reverse(first, last);
			return false;
		}
	}
}

void settest() {
	set<int> setNum{5, 1, 3, 4, 2};
	cout << "Set Size: " << setNum.size() << endl;

	for (const auto& num : setNum) {
		cout << num << ' ';
	}
	cout << endl;

	set<int>::iterator it = setNum.find(3);
	if (it != end(setNum)) {
		cout << "found number 3" << endl;
	} else {
		cout << "not found number 3" << endl;
	}

	setNum.erase(it);
	for (auto it = begin(setNum); it != end(setNum); ++it) {
		cout << *it << ' ';
	}
	cout << endl;


	string s = "ab";
	do {
		cout << s << '\n';
	} while (next_permu(begin(s), end(s)));
}