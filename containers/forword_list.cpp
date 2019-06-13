#include <forward_list>
#include <iostream>
#include <iterator>

void forword_test() {
	std::forward_list<int> l = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	l.erase_after(l.before_begin());
	for (auto n : l)
		std::cout << n << ' ';
	std::cout << '\n';

	auto fi = l.before_begin(); // std::next(l.begin());
	auto la = std::next(fi, 2);

	l.erase_after(fi, la);
	for (auto n : l)
		std::cout << n << " ";
	std::cout << '\n';

	l.push_front(1);
	for (auto n : l)
		std::cout << n << " ";
	std::cout << '\n';
}