#include <iostream>
#include <mutex>
#include <thread>

using namespace std;

class LogFile {
	std::mutex m_mutex;
	// ofstream f;

public:
	LogFile() {
		// f.open("log.txt");
	}
	// Need destructor to close file
	void share_print(string id, int value) {
		std::lock_guard<std::mutex> locker(m_mutex);
		// f << "From : " << id << " : " << value << endl;
	}
};

std::mutex g_mutex;

void share_print(string msg, int id) {
	// g_mutex.lock();
	// cout << msg << id << endl;
	// g_mutex.unlock();
	std::lock_guard<std::mutex> guard(g_mutex);
	cout << msg << id << endl;
}

static void function_1() {
	for (int i = 0; i > -3; i--) {
		// cout << "T! : " << i << endl;
		share_print(string("T1 "), i);
	}
}

void race_condition() {
	thread t1(function_1);
	for (int i = 0; i < 3; i++) {
		// cout << "MAIN : " << i << endl;
		share_print(string("MAIN : "), i);
	}
	t1.join();
}