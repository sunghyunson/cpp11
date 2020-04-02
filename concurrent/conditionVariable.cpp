#include <chrono>
#include <condition_variable>
#include <deque>
#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

std::deque<int> q;
std::mutex mu;
std::condition_variable cond;

static void function_1() {
	int count = 5;
	while (count > 0) {
		std::unique_lock<mutex> locker(mu);
		q.push_front(count);
		locker.unlock();
		// for cond
		cond.notify_one();
		std::this_thread::sleep_for(chrono::seconds(1));
		count--;
	}
}

// busy waiting
static void function_2() {
	int data = 0;
	while (data != 1) {
		std::unique_lock<mutex> locker(mu);
		if (!q.empty()) {
			data = q.back();
			q.pop_back();
			locker.unlock();
			cout << "t2 got a value from t1: " << data << endl;
		} else {
			locker.unlock();
		}
	}
}

static void function_3() {
	int data = 0;
	while (data != 1) {
		std::unique_lock<mutex> locker(mu);
		cond.wait(locker, []() {
			cout << "Spurious wake up ? " << endl;
			return !q.empty();
		});
		if (!q.empty()) {
			data = q.back();
			q.pop_back();
			locker.unlock();
			cout << "t2 got a value from t1: " << data << endl;
		}
	}
}

void conditionVariable() {
	thread t1(function_1);
	// thread t2(function_2);
	thread t2(function_3);

	t1.join();
	t2.join();
}