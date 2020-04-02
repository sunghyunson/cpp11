#include <iostream>
#include <memory>
#include <vector>

using namespace std;

template<typename T>
class TypeTester;

class MyClass : public std::enable_shared_from_this<MyClass>
{
private:
	int* data;
	std::weak_ptr<MyClass> other;
	std::string s;

public:
	MyClass()
	{
		data = new int[100];
		cout << "자원을 획득함" << endl;
	}
	MyClass(const std::string& s) : s(s)
	{
		cout << "자원을 획득함" << endl;
	}
	~MyClass()
	{
		cout << "소멸자 호출" << endl;
		if (data)
		{
			delete[] data;
		}
		data = nullptr;
	}

	shared_ptr<MyClass> get_shared_ptr()
	{
		// return shared_ptr<MyClass>(this);
		return shared_from_this();
	}

	void set_other(std::weak_ptr<MyClass> o)
	{
		other = o;
	}

	void access_other()
	{
		std::shared_ptr<MyClass> o = other.lock();
		if (o)
		{
			cout << "접근: " << o->name() << endl;
		}
		else
		{
			cout << "이미 소멸됨 -_-" << endl;
		}
	}

	std::string name()
	{
		return s;
	}
};


int main()
{
	vector<shared_ptr<MyClass>> vec;

	vec.push_back(shared_ptr<MyClass>(new MyClass()));
	vec.push_back(shared_ptr<MyClass>(vec[0]));
	vec.push_back(shared_ptr<MyClass>(vec[1]));

	cout << "1st 소멸" << endl;
	vec.erase(vec.begin());
	cout << vec.back().use_count() << endl;
	// cout << ad.use_count() << endl;

	cout << "next 소멸" << endl;
	vec.erase(vec.begin());
	// cout << ad.use_count() << endl;

	cout << "last 소멸" << endl;
	vec.erase(vec.begin());
	// cout << ad.use_count() << endl;

	shared_ptr<MyClass> pa(new MyClass());
	// shared_ptr<MyClass> pb(pa);
	pa.reset();
	cout << "pa use_count(): " << pa.use_count() << endl;
	// cout << "pb use_count(): " << pb.use_count() << endl;

	cout << "----------------" << endl;

	shared_ptr<MyClass> pa1 = make_shared<MyClass>();
	cout << "pa1 use_cound(): " << pa1.use_count() << endl;
	// BAD crash
	shared_ptr<MyClass> pa2 = pa1->get_shared_ptr();
	shared_ptr<MyClass> pa3 = pa1->get_shared_ptr();
	cout << "pa1 use_cound(): " << pa1.use_count() << endl;
	cout << "pa2 use_cound(): " << pa2.use_count() << endl;

	cout << "----------------" << endl;
	std::vector<shared_ptr<MyClass>> my_vec;
	my_vec.push_back(std::make_shared<MyClass>("자원 1"));
	my_vec.push_back(std::make_shared<MyClass>("자원 2"));

	my_vec[0]->set_other(my_vec[1]);
	my_vec[1]->set_other(my_vec[0]);

	// pa 와 pb 의 ref count 는 그대로다.
	std::cout << "my_vec[0] ref count : " << my_vec[0].use_count() << std::endl;
	std::cout << "my_vec[1] ref count : " << my_vec[1].use_count() << std::endl;

	// weak_ptr 로 해당 객체 접근하기
	my_vec[0]->access_other();

	// 벡터 마지막 원소 제거 (my_vec[1] 소멸)
	my_vec.pop_back();
	my_vec[0]->access_other(); // 접근 실패!

	return 0;
}
