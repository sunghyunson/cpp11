#include "Mystring.h"

/*
template <typename T>
void my_swap(T& a, T& b)
{
	T tmp(a);
	a = b;
	b = tmp;
}
 */

template <typename T>
void my_swap(T& a, T& b)
{
	T tmp(std::move(a));
	a = std::move(b);
	b = std::move(tmp);
}

int main()
{

	MyString str1("abc");
	MyString str2("def");
	std::cout << "-------------------" << std::endl;
	// // str1 = str2;
	// MyString str3 = str1 + str2;
	// str3.println();
	std::cout << "Before swap -------------------" << std::endl;
	str1.println();
	str2.println();

	std::cout << "After swap -------------------" << std::endl;
	my_swap(str1, str2);
	str1.println();
	str2.println();


/* 	MyString str1("abc");
	std::cout << "이동 전 --------" << std::endl;
	std::cout << "str1: ";
	str1.println();

	std::cout << "이동 후 --------" << std::endl;
	MyString str2(std::move(str1));
	std::cout << "str1: ";
	str1.println();
	std::cout << "str2: ";
	str2.println(); */
}