#include "mymodule1.h"
#include <dlfcn.h>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char** argv) {
	void* handle;

	char* error;
	Test* LTest;

	handle = dlopen("libmymodule.so", RTLD_LAZY);
	if (!handle) {
		perror("Open Library\n");
		exit(0);
	}

	std::function<Test*()> init_function;

	// Func_Init
	// Test* (*init_myFunc)() = (init_t*)dlsym(handle, "Func_Init");
	init_function = (Test * (*)()) dlsym(handle, "Func_Init");
	if ((error = dlerror()) != NULL) {
		printf("ERROR : %s\n", error);
		exit(0);
	}
	// LTest = init_myFunc();
	LTest = init_function();
	LTest->Count();
	LTest->Count();
	LTest->Print();

	// Func_destory
	destroy_t destroy_myFunc = (destroy_t)dlsym(handle, "Func_destory");
	destroy_myFunc(LTest);
}