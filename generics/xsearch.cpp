#include <algorithm>
#include <functional>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

template <typename T>
class slist_iterator;

template <typename T>
class slist;

template <typename T>
struct Node {
	template <typename K>
	friend class slist_iterator;
	template <typename K>
	friend class slist;

public:
	Node(T a, Node* n) : data(a), next(n) {}

private:
	T data;
	Node* next;
};

template <typename T>
class slist_iterator {
public:
	slist_iterator(Node<T>* p = nullptr) : current(p) {}

	slist_iterator& operator++() {
		current = current->next;
		return *this;
	}

	T& operator*() { return current->data; }
	// bool operator==(const slist_iterator& it) { return current == it.current; }
	bool operator!=(const slist_iterator& it) { return current != it.current; }

private:
	Node<T>* current;
};

template <typename T>
class slist {
public:
	typedef slist_iterator<T> iterator;
	typedef T value_type;

	iterator begin() { return iterator(head); }
	iterator end() { return iterator(nullptr); }

public:
	slist() : head(nullptr) {}
	~slist() {
		Node<T>* node = head;
		while (node) {
			Node<T>* temp = node;
			node = node->next;
			delete temp;
		}
	}
	void push_front(const T& a) {
		cout << "push_front: " << a << endl;
		head = new Node<T>(a, head);
	}
	void print_data() {
		Node<T>* node = head;
		while (node) {
			cout << node->data << ' ';
			node = node->next;
		}
		cout << endl;
	}

private:
	Node<T>* head;
};



// TODO: step 1
char* xstrchr(char* s, char value) {
	while (*s != 0 && *s != value) {
		++s;
	}
	return *s == 0 ? 0 : s;
}

// TODO: step 2
// range generalization
char* xstrchr(char* first, char* last, char value) {
	while (first != last && *first != value) {
		++first;
	}
	return first == last ? 0 : first;
}

// TODO: step 3, 4
template <typename T, typename V>
T xfind(T first, T last, V value) {
	while (first != last && *first != value) {
		++first;
	}
	// return first == last ? 0 : first;
	return first;
}

void xsearch() {
	char s[] = "abcdefg";
	char* p = xstrchr(s, 'k');
	if (p == 0) {
		cout << "Cannot find" << endl;
	} else {
		cout << *p << endl;
	}

	p = xstrchr(s + 1, s + 5, 'd');
	if (p == 0) {
		cout << "Cannot find" << endl;
	} else {
		cout << *p << endl;
	}

	double x[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	double* xpos = xfind(x, x + 4, 3.0);
	if (xpos == x + 4) {
		cout << "Cannot find" << endl;
	} else {
		cout << *xpos << endl;
	}

	slist<int> ss;
	ss.push_front(10);
	ss.push_front(20);
	ss.push_front(30);

	// ss.print_data();

	slist<int>::iterator iter = ss.begin();
	while (iter != ss.end()) {
		cout << *iter << endl;
		++iter;
	}
	// for (auto val : ss) {
	// 	cout << val << endl;
	// }
	// for (auto iv = begin(ss); iv != end(ss); ++iv) {
	// 	cout << *iv << " -> ";
	// }
	// cout << endl;

	// for (auto val : ss) {
	// 	cout << val << endl;
	// }

	auto n = xfind(ss.begin(), ss.end(), 20);
	if (n != ss.end()) {
		cout << *n << endl;
	}

	// slist<int>
}