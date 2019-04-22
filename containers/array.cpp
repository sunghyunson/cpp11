#include <array>
#include <iostream>

using namespace std;

void array_test() {
	// aggregate-initialization
	std::array<int, 3> arr = {1, 2, 3};
	std::array<int, 3>::value_type myval= 3;
}