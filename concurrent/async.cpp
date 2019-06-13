#include <chrono>
#include <future>
#include <iostream>
#include <list>
#include <random>

using namespace std;

// int DoSomething(char c) {
// 	std::default_random_engine dre(c);
// 	std::uniform_int_distribution<int> id(10, 1000);

// 	for (int i = 0; i < 10; i++) {
// 		this_thread::sleep_for(chrono::milliseconds(id(dre)));
// 		cout.put(c).flush();
// 	}

// 	return c;
// }

void DoSomething(int num, char c) {
	try {
		std::default_random_engine dre;
		std::uniform_int_distribution<int> id(10, 1000);

		for (int i = 0; i < 5; i++) {
			this_thread::sleep_for(chrono::milliseconds(id(dre)));
			cout.put(c).flush();
		}
	} catch (const exception& e) {
		cerr << "THREAD-EXCEPTION (thread " << this_thread::get_id() << ") : " << e.what() << endl;
	} catch (...) {
		cerr << "TRHEAD_EXCEPTION (thread " << this_thread::get_id() << ") : " << endl;
	}
}

// int func1() { return DoSomething('.'); }

// int func2() { return DoSomething('+'); }

auto async() {
	try {
		thread t1(DoSomething, 5, '.');
		cout << "  - started foreground thread " << t1.get_id() << endl;

		for (int i = 0; i < 5; i++) {
			thread t(DoSomething, 10, (char)('a' + i));
			cout << "  - deatch started background thread " << t.get_id() << endl;
			t.detach();
		}

		cout << " join foreground thread " << t1.get_id() << endl;
		t1.join();
	} catch (exception& e) {
		cerr << "EXCEPTION : " << e.what() << endl;
	}
	cout << endl;

	// cout << "Starting func() in background "
	// 	 << "and func2() in foreground: " << endl;

	// std::future<int> result1(std::async(std::launch::async, func1));
	// int result2 = func2();
	// int result = result1.get() + result2;
	// cout << "\nresult of func1() + func2() : " << result << endl;
}