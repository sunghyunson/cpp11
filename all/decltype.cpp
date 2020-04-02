#include <iostream>

using namespace std;

class c
{
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

public:
	int& operator[](int i)
	{
		return arr[i];
	}
};

template <typename T>
auto changearr(T& c, int index) -> decltype(c[index])
{
	return c[index];
}

int main()
{
	c myclass;
	changearr(myclass, 3) = 100;
	cout << myclass[3];
}