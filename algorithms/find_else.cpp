#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

void find_family()
{
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

	auto p = find(begin(a), end(a), 19);
	if (p == end(a))
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "found" << endl;
	}

	p = find_if(begin(a), end(a), [](int n) { return (n > 4); });
	if (p == end(a))
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "found" << endl;
	}
}