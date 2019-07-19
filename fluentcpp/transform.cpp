#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int getFirst(std::pair<const int, string> item)
{
	return item.first;
}

int main()
{
	map<int, string> m = {{1, "foo"}, {42, "bar"}, {7, "baz"}};
	vector<int> keys;
	keys.reserve(m.size());
	// ITEM 1
	std::transform(begin(m), end(m), back_inserter(keys), getFirst);

	for (auto const v : keys)
	{
		cout << v << ' ';
	}
	cout << endl;

	// ITEM 2
	vector<int> numbers1 = {1, 5, 42, 7, 8};
	vector<int> numbers2 = {10, 7, 4, 2, 2};
	vector<int> results;
	std::transform(begin(numbers1), end(numbers1), numbers2.begin(), std::back_inserter(results), [](int i, int j) {
		return i + j;
	});
	for (auto const v : results)
	{
		cout << v << ' ';
	}
	cout << endl;
	return 0;
}
