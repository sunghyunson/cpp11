#include <algorithm>
#include <iostream>
#include <vector>

template <typename InputIterator1, typename InputIterator2, typename OutputInterator>
OutputInterator my_set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
								  InputIterator2 last2, OutputInterator out) {
	auto current1 = first1;
	auto current2 = first2;

	while (current1 != last1) {
		if (current2 == last2) {
			std::copy(current1, last1, out);
			return out;
		}

		if (*current1 < *current2) {
			*out = *current1;
			++out;
			++current1;
		} else {
			// RE-ORDER
			// if (*current2 < *current1) {
			// 	++current2;
			// } else {
			// 	++current1;
			// 	++current2;
			// }
			if (!(*current2 < *current1)) {
				++current1;
			}
			++current2;
		}
	}

	return out;
}

int main() {
	std::vector<int> A = {1, 2, 3, 6, 7, 7, 10, 11, 12};
	std::vector<int> B = {4, 6, 7, 8};

	std::vector<int> results;

	my_set_difference(std::begin(A), std::end(A), std::begin(B), std::end(B), back_inserter(results));
	for (auto const val : results)
	{
		std::cout << val << ' ';
	}
	std::cout << std::endl;
}