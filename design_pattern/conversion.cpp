#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Point {
private:
	int m_x;
	int m_y;

public:
	Point(int x) : m_x(x), m_y(0) {}
	Point(int x, int y) : m_x(x), m_y(y) {}
	operator int() { return m_x; }
};

class OFile {
private:
	FILE* m_file;

public:
	explicit OFile(const char* name, const char* mode = "wt") {
		cout << "CTR: " << endl;
		m_file = fopen(name, mode);
	}
	~OFile() {
		cout << "DTR: " << m_file << endl;
		if (m_file) {
			fclose(m_file);
		}
		m_file = nullptr;
	}
	operator FILE*() { return m_file; }
};

void foo(OFile f) {}

int main() {
	int n = 0;
	Point point(1, 2);
	n = point;
	cout << n << endl;

	point = 3;
	n = point;
	cout << n << endl;

	OFile f("a.txt");
	foo(f); //--> crash twice release?
	// foo(OFile("hello"));
	cout << "hello" << endl;

	// shared_ptr<int> pp1 = new int; //-->no explicit
	shared_ptr<int> pp2(new int);
}