#ifndef _MYMODULE_H_
#define _MYMODULE_H_

#include <stdio.h>
#include <string>

using namespace std;

class Test {
private:
	int count;

public:
	Test();
	~Test() { printf("Destory\n"); }
	void Count();
	void Print();
};
extern "C" class Test* Func_Init();
extern "C" void Func_destory(class Test* aTest);

typedef void (*destroy_t)(Test*);
typedef Test* init_t();
typedef int MY_INT;
typedef int MY_LL();
#endif