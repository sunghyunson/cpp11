#include <functional>
#include <iostream>
#include <memory.h>
#include <type_traits>

using namespace std;

struct Point3D {
	Point3D(int a, int b, int c) : x(a), y(b), z(c) {}
	int x, y, z;
	int* begin() {
		cout << "internal begin" << endl;
		return &x;
	}
	int* end() {
		cout << "internal end" << endl;
		return &z + 1;
	}
};

int* begin(Point3D& p) {
	cout << "external " << endl;
	return &(p.x);
}
int* end(Point3D& p) {
	cout << "external " << endl;
	return &(p.z) + 1;
}

int main() {
	Point3D point(1, 2, 3);
	// for (auto p = begin(point); p != end(point); ++p) {
	// 	auto n = *p;
	// 	cout << n << endl;
	// }

	for (const auto& p : point) {
		cout << p << endl;
	}
	return 0;
}