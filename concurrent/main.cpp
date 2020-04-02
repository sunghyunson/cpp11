#include <iostream>
#include <thread>

using namespace std;

static void function_1() {
	for (int i = 0; i > -100; i--) {
		cout << "T! : " << i << endl;
	}
}

class Fctor {
public:
	// void operator()() {
	// 	for (int i = 0; i < 10; i++) {
	// 		std::cout << "from FUNCTOR : " << i << std::endl;
	// 	}
	// }
	void operator()(string&& msg) {
		// parameter ALWAYS call by value not reference
		cout << "t1 says : " << msg << endl;
		msg = "Trust is the mother of deceit.";
	}
};

extern void race_condition();
extern void conditionVariable();
extern void future();
extern void async();

int main() {
	async();
	future();
	// conditionVariable();
	race_condition();

	// Fctor fct;
	// string s = "Where there is no trust, there is no love";
	// thread t1((Fctor()), s);
	// thread t1((Fctor()), std::ref(s));
	// thread t1((Fctor()), std::move(s));
	// t1.join();
	// cout << "MAIN : " << s << endl;

	// thread t1(function_1); // t1 starts running

	// using RAII
	// Wrapper w(t1)

	// for (int i = 0; i < 100; i++) {
	// 	cout << "from main : " << i << endl;
	// }
	// t1.join();

	// t1.join(); // main thread waits for t1 to finish
	// t1.detach(); // t1 will freely on its own -- daemon process

	// if (t1.joinable()) {
	// 	t1.join();
	// }

	return 0;
}