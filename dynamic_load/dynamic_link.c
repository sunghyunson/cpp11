#include <stdio.h>
#include "dl_header.h"

int main()
{
	int result = 0;
	result = add(5, 6);
	printf("%d\n", result);

	result = sub(10, 4);
	printf("%d\n", result);

	testPrint();
	return 0;
}