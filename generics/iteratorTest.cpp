#include <algorithm>
#include <iostream>
#include <list>

using namespace std;

template <typename T>
struct my_iterator_traits {
	using iterator_category = typename T::iterator_category;
};

template <typename T>
struct my_iterator_traits<T*> {
	using iterator_category = random_access_iterator_tag;
};


template <typename T>
void xadvance_impl(T& p, int n, random_access_iterator_tag) {
	p = p + n;
}

template <typename T>
void xadvance_impl(T& p, int n, input_iterator_tag) {
	while (n--) {
		++p;
	}
}

template <typename T>
void xadvance(T& p, int n) {
	xadvance_impl(p, n, typename my_iterator_traits<T>::iterator_category());
}



void iterator_category() {
	list<int> s(10, 3);
	// sort(begin(s), end(s)); FIXME: error
	s.sort();

	int x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	list<int> c(x, x + 10);
	auto p1 = begin(c);
	cout << *p1 << endl;
	xadvance(p1, 5);
	cout << *p1 << endl;

	int* p2 = x;
	xadvance(p2, 5); // FIXME: add layer for category
	cout << *p2 << endl;
}