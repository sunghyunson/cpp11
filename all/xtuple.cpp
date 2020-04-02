#include <iostream>

using namespace std;

template <typename T>
void xtuple_size(const T& a) {
	cout << "size is : " << T::N << endl;
}

template <typename... Types>
class xtuple {
public:
	xtuple() { cout << "type CTR" << endl; }
};

template <>
class xtuple<> {
public:
	xtuple() { cout << "empty CTR" << endl; }
};

template <typename T, typename... Types>
class xtuple<T, Types...> : private xtuple<Types...> {
public:
	xtuple() { cout << "normal CTR" << endl; }
	xtuple(const T& a, Types... args) : first_(a), xtuple<Types...>(args...) {}
	enum { N = 1 + sizeof...(Types) };

public:
	T first_;
};

int main() {
	xtuple<int, char, double> t(1, 'a', 3.4);
	// cout << xtuple_size(t) << endl;
	xtuple_size(t);
	return 0;
}