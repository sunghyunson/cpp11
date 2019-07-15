#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

void print_separator(string str)
{
	cout << "------" << str.c_str() << "------\n";
}

void convert(uint64_t value)
{
	value = 62;
	uint8_t* ptr;

	ptr = (uint8_t*)&value;
	cout << "value is : ";
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", ptr[i]);
	}
	cout << endl;

	float ccc;
	memcpy(&ccc, &value, sizeof(ccc));
	ptr = (uint8_t*)&ccc;
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", ptr[i]);
	}
	cout << endl;

	cout << "converted " << ccc << endl;
	cout << endl;
}

int main()
{
	cout << "float" << endl;
	uint8_t* ptr;
	float aa = -13.73;
	ptr = (uint8_t*)&aa;
	for (int i = 0; i < 4; i++)
	{
		printf("%d ", ptr[i]);
	}
	cout << endl;

	uint64_t converted = 0;
	memcpy(&converted, &aa, sizeof(aa));
	ptr = (uint8_t*)&converted;
	for (int i = 0; i < 8; i++)
	{
		printf("%d ", ptr[i]);
	}
	cout << endl;
	convert(converted);

	char cmd[51] = {
		0,
	};
	strncpy(cmd, "route add ", sizeof(char) * 5);
	strncat(cmd, "192.168.10.1", sizeof(char) * 50);
	cout << "cmd: " << cmd << endl;
}