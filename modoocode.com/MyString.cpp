#include "Mystring.h"

MyString::MyString()
{
	std::cout << "생성자 호출 !" << std::endl;
	string_length = 0;
	memory_capacity = 0;
	string_content = nullptr;
}

MyString::MyString(const char* str)
{
	std::cout << "생성자 호출 ! - " << str << std::endl;
	string_length = strlen(str);
	memory_capacity = string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
	{
		string_content[i] = str[i];
	}
}

MyString::MyString(const MyString& str)
{
	std::cout << "복사 생성자 호출 !" << std::endl;
	string_length = str.string_length;
	string_content = new char[string_length];

	for (int i = 0; i != string_length; i++)
	{
		string_content[i] = str.string_content[i];
	}
}

MyString::MyString(MyString&& str)
{
	std::cout << "이동 생성자 호출 !" << std::endl;
	string_length = str.string_length;
	string_content = str.string_content;
	memory_capacity = str.memory_capacity;

	str.string_content = nullptr;
	str.string_length = 0;
	str.memory_capacity = 0;
}

MyString::~MyString()
{
	std::cout << "소멸자 호출 !" << string_content << std::endl;
	delete[] string_content;
	// string_content = nullptr;
}

void MyString::reserve(int size)
{
	if (size > memory_capacity)
	{
		char* prev_string_content = string_content;

		string_content = new char[size];
		memory_capacity = size;

		for (int i = 0; i != string_length; i++)
		{
			string_content[i] = prev_string_content[i];
		}

		if (prev_string_content != nullptr)
		{
			delete[] prev_string_content;
		}
	}
}

MyString MyString::operator+(const MyString& s)
{
	MyString str;
	str.reserve(string_length + s.string_length);
	for (int i = 0; i < string_length; i++)
	{
		str.string_content[i] = string_content[i];
	}
	for (int i = 0; i < s.string_length; i++)
	{
		str.string_content[string_length + i] = s.string_content[i];
	}
	str.string_length = string_length + s.string_length;

	return str;
}

MyString& MyString::operator=(const MyString& s)
{
	std::cout << "복사 연산자 = " << std::endl;

	if (s.string_length > memory_capacity)
	{
		delete[] string_content;
		string_content = new char[s.string_length];
		memory_capacity = s.string_length;
	}

	string_length = s.string_length;
	for (int i = 0; i != string_length; i++)
	{
		string_content[i] = s.string_content[i];
	}

	return *this;
}

MyString& MyString::operator=(MyString&& s)
{
	std::cout << "이동 연산자 = " << std::endl;
	string_content = s.string_content;
	memory_capacity = s.memory_capacity;
	string_length = s.string_length;

	s.string_content = nullptr;
	s.memory_capacity = 0;
	s.string_length = 0;
	return *this;
}

int MyString::length() const
{
	return string_length;
}
void MyString::print()
{
	for (int i = 0; i != string_length; i++)
	{
		std::cout << string_content[i];
	}
}

void MyString::println()
{
	for (int i = 0; i != string_length; i++)
	{
		std::cout << string_content[i];
	}
	std::cout << std::endl;
}