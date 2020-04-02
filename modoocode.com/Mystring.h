#include <iostream>
#include <cstring>

class MyString
{
	char* string_content;
	int string_length;
	int memory_capacity;

public:
	MyString();
	MyString(const char* str);
	MyString(const MyString& str);
	MyString(MyString&& str);

	void reserve(int size);
	MyString operator+(const MyString& s);
	MyString& operator=(const MyString& s);
	MyString& operator=(MyString&& s);
	~MyString();

	int length() const;
	void print();
	void println();
};