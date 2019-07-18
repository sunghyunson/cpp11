#include <iostream>

using namespace std;

// TODO 2 : interface
#define interface struct
interface IValidator {
	virtual bool validate(char c) = 0;
	virtual bool isComplete(string s) { return true; };
	~IValidator() {}
};

class LineEdit {
	string data;
	// TODO 2 : interface
	IValidator* m_validator = nullptr;

public:
	// TODO 1 : virtual
	virtual bool validate(char c) { return true; }

	// TODO 2 : interface
	void setValidator(IValidator* p) { m_validator = p; }

	string getData() {
		data.clear();

		while (1) {
			char c = getchar();
			if (c == '\n')
				break;
			// TODO 2 : interface
			if (m_validator == nullptr || m_validator->isComplete(data)) {
				break;
			}

			// if (isdigit(c))
			// TODO 1 : virtual
			// if (validate(c))
			// TODO 2 : interface
			if (m_validator->validate(c)) {
				data.push_back(c);
				cout << c << " ";
			}
		}
		cout << endl;
		return data;
	}
};

// TODO 1 : virtual
class DigitEdit : public LineEdit {
public:
	virtual bool validate(char c) { return isdigit(c); }
};

// TODO 2 : interface
class LimitDigitValidator : public IValidator {
	int m_value;

public:
	LimitDigitValidator(int n) : m_value(n) {}

	bool validate(char c) override { return isdigit(c); }

	virtual bool isComplete(string s) override { return s.size() == m_value; };
};

int main() {
	// LineEdit edit;
	// TODO 1 : virtual
	// DigitEdit edit;
	// TODO 2 : interface
	LineEdit edit;
	LimitDigitValidator v(5);
	edit.setValidator(&v);

	string s = edit.getData();
	cout << "string is --> " << s << endl;
}