#include <random>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


template <typename ForwardIterator1, typename ForwardIterator2>
bool my_is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, ForwardIterator2 last2)
{
	// ADD
	if (std::distance(first1, last1) != std::distance(first2, last2))
		return false;

	// USE mismatch
	auto starter = std::mismatch(first1, last1, first2, last2);

	// for (auto current1 = first1; current1 != last1; ++current1)
	for (auto current1 = starter.first; current1 != last1; ++current1)
	{
		// USE counting each value only once
		if (std::find(starter.first, current1, *current1) == current1)
		{
			// add
			auto const numberOfOccurencesIn1 = std::count(first1, last1, *current1);
			auto const numberOfOccurencesIn2 = std::count(first2, last2, *current1);
			if (numberOfOccurencesIn1 != numberOfOccurencesIn2)
			{
				return false;
			}
			// REMOVE
			// if (std::find(first2, last2, *current1) == last2)
			// {
			// 	return false;
			// }
		}
	}
	return true;
}


int main()
{
	vector<int> v = {1, 2, 3, 4, 5};
	cout << "next_permutation: " << std::prev_permutation(begin(v), end(v)) << endl;

	cout << "vector is --> " << endl;
	for (const auto elem : v)
	{
		cout << elem << ' ';
	}
	cout << endl;

	// vector<int> numbers = {1, 2, 3, 4};
	// do
	// {
	// 	for (int n : numbers) cout << n << ' ';
	// 	cout << '\n';
	// } while (next_permutation(begin(numbers), end(numbers)));

	vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	auto first = begin(nums) + 2;
	auto last = begin(nums) + 6;
	auto pos = begin(nums) + 9;
	rotate(first, last, pos);

	cout << "rotate vector is --> " << endl;
	for (const auto elem : nums)
	{
		cout << elem << ' ';
	}
	cout << endl;

	// ITEM random permutation
	random_device randomDevice;
	mt19937 generator(randomDevice());

	shuffle(begin(nums), end(nums), generator);
	cout << "random vector is --> " << endl;
	for (const auto elem : nums)
	{
		cout << elem << ' ';
	}
	cout << endl;

	// ITEM reverse
	nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	reverse(begin(nums), end(nums));
	cout << "reverse vector is --> " << endl;
	for (const auto elem : nums)
	{
		cout << elem << ' ';
	}
	cout << endl;

	vector<int> v1 = {1, 4, 3, 2, 5, 5};
	vector<int> v2 = {4, 2, 3, 1, 5, 7};
	vector<int> v3 = {2, 3, 4, 5, 6, 1};

	cout << "is_permutation: " << is_permutation(v1.begin(), v1.end() - 1, v2.begin()) << endl; //c++11 style
	cout << "is_permutation: " << is_permutation(v1.begin(), v1.end(), v3.begin(), v3.end()) << endl; //c++14 style


	cout << "my_is_permutation: " << my_is_permutation(v1.begin(), v1.end(), v2.begin(), end(v2)) << '\n';
}