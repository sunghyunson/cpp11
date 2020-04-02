#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <chrono>

using namespace std;

int randomNumberGenerator()
{
	static random_device device;
	static mt19937 engine(device());//{device()};
	static uniform_int_distribution<> distribution(1, 6);
	return distribution(engine);
}


class MyClass
{
public:
	explicit MyClass(int i) : i_(i){};

private:
	int i_;
};


MyClass* myObjects = static_cast<MyClass*>(malloc(5 * sizeof(MyClass)));

int main()
{
	// Allocate a buffer that can contain 5 objects of MyClass

	// Call constructor on each object, with value 3
	std::uninitialized_fill(myObjects, myObjects + 5, 3);

	// Use myObjects...

	// Call destructor on each object
	std::for_each(myObjects, myObjects + 5, [](const MyClass& object) { object.~MyClass(); });

	// Deallocate the buffer
	free(myObjects);
	myObjects = nullptr;

	vector<int> vv = {3, 3, 3, 3, 3, 3};
	iota(begin(vv), end(vv), 5);
	for (auto const v : vv)
	{
		cout << v << ' ';
	}
	cout << endl;

	// ITEM generate_n
	vector<int> numbers;
	generate_n(back_inserter(numbers), 10, randomNumberGenerator);
	for (auto const v : numbers)
	{
		cout << v << ' ';
	}
	cout << endl;


	return 0;
}