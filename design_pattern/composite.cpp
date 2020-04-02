#include <iostream>
#include <vector>

using namespace std;

class Data {
public:
	Data(string name) : m_name(name) {}
	virtual ~Data() {}
	virtual int getSize() = 0;

private:
	string m_name;
};

class Folder : public Data {
public:
	Folder(string name) : Data(name) {}
	virtual ~Folder() {}
	virtual int getSize() {
		int size = 0;
		// for (int i = 0; i < files.size(); ++i) {
		// 	size += files[i]->getSize();
		// }
		for (const auto& f : files) {
			size += f->getSize();
		}
		return size;
	}
	void addItem(Data* item) { files.push_back(item); }

private:
	vector<Data*> files;
};

class File : public Folder {
public:
	File(string name, int size) : Folder(name), m_size(size) {}
	virtual ~File() {}
	virtual int getSize() { return m_size; }

private:
	int m_size;
};

int main() {
	Folder* root = new Folder("root");
	Folder* fo1 = new Folder("A");
	Folder* fo2 = new Folder("B");

	// 파일은 자신만의 크기가 있습니다.
	File* f1 = new File("a.txt", 10);
	File* f2 = new File("b.txt", 20);
	File* f3 = new File("c.txt", 30);

	root->addItem(fo1);
	root->addItem(fo2);

	fo2->addItem(f3);
	fo1->addItem(f2);
	root->addItem(f1);

	// 폳더는 자신의 크기는 없지만 크기를 구할 수 있습니다.
	cout << f1->getSize() << endl;   // 10
	cout << fo1->getSize() << endl;  // 50
	cout << root->getSize() << endl; // 60

	delete f1;
	delete f2;
	delete f3;
	delete fo1;
	delete fo2;
	delete root;
}
