#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void reverse_rotate() {
	stringstream ss;
	string data = "good morining sir";
	ss.str(data);

	cout << "origin: " << data << endl;
	cout << "revere char" << endl;
	string word;
	while (ss >> word) {
		reverse(begin(word), end(word));
		cout << word;
		if (ss.eof())
			cout << endl;
		else
			cout << ' ';
	}

	cout << "reverse string" << endl;
	ss.clear();
	ss.str(data);
	vector<string> str_vec;
	while (ss >> word) {
		str_vec.push_back(word);
	}
	reverse(str_vec.begin(), str_vec.end());
	for (const auto& value : str_vec) {
		cout << value << ' ';
	}
	cout << endl;

	int a[]{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	cout << "---rotate---" << endl;
	cout << "before a : ";
	for (const auto& value : a) {
		cout << value << ' ';
	}
	cout << endl;
	rotate(a + 2, a + 4, a + 6);
	cout << "Do rotate(a + 2, a + 4, a + 6)" << endl;
	cout << "after a : ";
	for (const auto& value : a) {
		cout << value << ' ';
	}
	cout << endl;
}