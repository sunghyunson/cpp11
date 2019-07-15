#include <iostream>

using namespace std;


// int k = 0;

template <typename T>
void f(T& param)
{
	static int f = 0;
	f++;
	cout << "f: " << f << endl;
};

template <typename T>
void f_const(const T& param)
{
	static int f_con = 0;
	f_con++;
	cout << "f_const: " << f_con << endl;
};

template <typename T>
void g(T&& param)
{
	static int g = 0;
	g++;
	cout << "g: " << g << endl;
}

template <typename T>
void g(const T&& param);

template <typename T>
void h(T param)
{
	static int h = 0;
	h++;
	cout << "h: " << h << endl;
};
template <typename T>
void h_const(const T param)
{
	// param = 22;
	cout << param << endl;
};



int main()
{
	int x = 27;
	const int cx = x;
	const int& rx = x;

	// cout << "-----reference--------" << endl;
	f(x); // g<int>(int&)
	f(cx); // g<int const>(int const&)
 	f(rx); // g<int const>(int const&)
	// g(22); 			//FIXME: error

	f_const(x); // g_const<int>(int const&)
	f_const(cx); // g_const<int>(int const&)
	f_const(rx); // g_const<int>(int const&)
	f_const(22); // g_const<int>(int const&);

	cout << "-----universal--------" << endl;
	g(x);					// h<int&>(int&)
	g(cx);					// h<int const&>(int const&)
	g(rx);					// h<int const&>(int const&)
	g(33);					// h<int>(int&&)
	// g_const(x);				// FIXME: error
	// g_const(cx);			// FIXME: error
	// g_const(rx);			// FIXME: error
	// g_const(33);			// h_const<int>(int const&&)

	cout << "-----normal--------" << endl;
	h(x);			// f<int>(int)
	h(cx);			// f<int>(int)
	h(rx);			// f<int>(int)
	h(11);			// f<int>(int)
	h_const(x);		// f_const<int>(int)
	h_const(cx);	// f_const<int>(int)
	h_const(rx);	// f_const<int>(int)
	h_const(11);	// f_const<int>(int)


	return 0;
}
