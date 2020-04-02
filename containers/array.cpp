#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>

using namespace std;

void array_test() {
	// construction uses aggregate initialization
	std::array<int, 3> a1{{1, 2, 3}};  // double-braces required in C++11 prior to the CWG 1270 revision
									   // (not needed in C++11 after the revision and in C++14 and beyond)
	std::array<int, 3> a2 = {1, 2, 3}; // never required after =
	std::array<std::string, 2> a3 = {std::string("a"), "b"};

	// container operations are supported
	std::sort(a1.begin(), a1.end());
	std::reverse_copy(a2.begin(), a2.end(), std::ostream_iterator<int>(std::cout, " "));

	std::cout << '\n';

	// ranged for loop is supported
	for (const auto& s : a3)
		std::cout << s << ' ';

	// aggregate-initialization
	std::array<int, 4> numbers = {2, 4, 6, 8};

	cout << "Second element: " << numbers[1] << '\n';

	numbers[0] = 5;

	cout << "All numbers : ";
	for (auto i : numbers) {
		cout << ' ' << i;
	}
	cout << '\n';

	numbers.fill(3);
	cout << "All numbers after fill : ";
	for (auto i : numbers) {
		cout << ' ' << i;
	}
	cout << '\n';
}