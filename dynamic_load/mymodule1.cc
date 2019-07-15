#include "mymodule1.h"

Test::Test() {
	printf("Init\n");
	count = 0;
}

int aa() { return 3; }

void Test::Count() {
    int (*ffc)() = aa;
	MY_LL aa;
	count++;
}

void Test::Print() { printf("Count is %d\n", count); }

class Test* Func_Init() {
	Test* myTest;
	myTest = new Test;
	return myTest;
}

void Func_destory(class Test* aTest) { delete aTest; }

void Func_Test(class Test* aTest) {
	aTest->Count();
	aTest->Print();
}