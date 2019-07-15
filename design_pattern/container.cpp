#include <iostream>
#include <vector>

using namespace std;

/*
struct Node {
	int m_data;
	Node* m_next;
	Node(int data, Node* next) : m_data(data), m_next(next) {}
};

class slist {
private:
	Node* m_head;

public:
	slist() : m_head(nullptr) {}
	~slist();
	void push_front(int n) { m_head = new Node(n, m_head); }
	int front() { return m_head->m_data; }
};

slist::~slist() {
	Node* temp;
	while (m_head) {
		temp = m_head;
		m_head = m_head->m_next;
		delete temp;
	}
}
*/

/*
class Object {
public:
	virtual ~Object() {}
};

struct Node {
	Object* m_data;
	Node* m_next;
	Node(Object* data, Node* next) : m_data(data), m_next(next) {}
};

class slist {
private:
	Node* m_head;

public:
	slist() : m_head(nullptr) {}
	~slist(){}
	void push_front(Object* data) { m_head = new Node(data, m_head); }
	Object* front() { return m_head->m_data; }
};

class Integer : public Object {
public:
	Integer(int n) : m_value(n) {}
	int getValue() { return m_value; }

private:
	int m_value;
};
*/

template <typename T>
struct Node {
	T m_data;
	Node* m_next;
	Node(T data, Node* next) : m_data(data), m_next(next) {}
};

template <typename T>
class slist {
private:
	Node<T>* m_head;

public:
	slist() : m_head(nullptr) {}
	void push_front(T n) { m_head = new Node<T>(n, m_head); }
	T front() { return m_head->m_data; }
};

int main() {
	// slist slist;

	/* 	slist.push_front(10);
		slist.push_front(20);
		slist.push_front(30);
		cout << slist.front() << endl; */

	/* 	slist.push_front(new Integer(10));
		slist.push_front(new Integer(20));
		slist.push_front(new Integer(30));
		Integer* val = static_cast<Integer*>(slist.front());
		cout << val->getValue() << endl; */

	slist<string> my_slist;
	my_slist.push_front("good morning");
	my_slist.push_front("afternoon");
	my_slist.push_front("evening");
	string val = my_slist.front();
	cout << val << endl;

	int* p = (int*)malloc(100);
	int n = 3;
	double* p2 = (double*)&n;
	// cout << *p2 << endl;
	// *p2 = 3.4;
	constexpr int c = 10;
	int* pp = (int*)&c;
	*pp = 20;
	cout << c << " " << *pp << endl;

	int vvv = 10;
	const int cc = vvv;
	int* ppp = (int*)&cc;
	*ppp = 20;
	cout << cc << " " << *ppp << endl;

	return 0;
}