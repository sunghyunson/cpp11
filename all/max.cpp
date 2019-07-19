#include <type_traits>
#include <iostream>

using namespace std;

// template <typename T, typename U>
// inline U max_impl(T a, T b, true_type)
// // inline T max_impl(T a, T b, Int2Type<1>)
// {
// 	return *a < *b ? *b : *a;
// }

// template <typename T, typename U>
// inline T max_impl(T a, T b, false_type)
// // inline T max_impl(T a, T b, Int2Type<0>)
// {
// 	return a < b ? b : a;
// }

// int max_impl(int a, int b)
// {
// 	return a;
// }

template <typename T>
inline auto max_impl(T a, T b)
{
	return 3.4L;
}

template <typename T>
auto max2(T a, T b)
{
	return max_impl(a, b);
	// return max_impl(a, b, integral_constant<bool, is_pointer<T>::value>());
	// integral_constant<bool, is_pointer<T>::value> aa;
	// cout << "is_pointer<T>::value : " << is_pointer<T>::value << endl;
	// return 0;
	// return max_impl(a, b, integral_constant<bool, true>::value);
	// return max_impl(a, b, Int2Type<is_pointer<T>::value>());
}

template <typename T, typename U>
U my_func(T a)
{
	cout << a << endl;
	return 3.14;
}


int main()
{
	int val = 3;
	double k = my_func<int, double>(3);
	cout << "my_func : " << k << endl;
	int a = 3;
	int b = 7;
	double gg = max2(a, b);
	cout << gg << endl;
	// cout << max2<int, int>(a, b) << endl;
	// int *c = &a;
	// int *d = &b;
	// int rr = max2(c, d);
	// cout << rr << endl;
	return 0;
}
