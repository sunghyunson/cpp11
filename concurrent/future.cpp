#include <chrono>
#include <condition_variable>
#include <deque>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

void factorial_ori(int N, int& x) {
	int res = 1;
	for (int i = N; i > 1; i--) {
		res *= i;
	}

	cout << "Result is : " << res << endl;
	x = res;
}

int factorial(int N) {
	int res = 1;
	for (int i = N; i > 1; i--) {
		res *= i;
	}

	cout << "Result is : " << res << endl;
	return res;
}

void future() {
	int x;
	// std::thread t1(factorial, 5, ref(x));
	// t1.join();

	std::future<int> fu = std::async(factorial, 4);
	x = fu.get();
	// fu.get(); // crash

	cout << "MAIN=> x is " << x << endl;
}