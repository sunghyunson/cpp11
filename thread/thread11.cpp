#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <pthread.h>
#include <vector>

using namespace std;

mutex g_mutex;

void counter(int id, int length)
{
	vector<int> vec = {1, 2, 3};
	// auto native = this_thread::get_id().native_handle();
	for (int i = 0; i <= length; i++)
	{
		g_mutex.lock();
		{
			// lock_guard<mutex> gurad(g_mutex);
			cout << "counter[" << id << "]"
				 << " : " << i << endl;
		}
		g_mutex.unlock();
		this_thread::sleep_for(chrono::milliseconds(100));
	}
	// cout << this_thread::get_id();
	// this_thread::get_id
	pthread_detach(pthread_self());
	pthread_exit(nullptr);
}

int main()
{
	thread t1(counter, 100, 5);
	thread t2(counter, 2, 7);
	int a[20] = {
		0,
	};
	int* p;

	// t1.detach();
	// t2.detach();
	std::this_thread::sleep_for(chrono::seconds(5));
	{
		// lock_guard<mutex> gurad(g_mutex);
		cout << "t1 is joinable : " << t1.joinable() << endl;
		cout << "t2 is joinable : " << t2.joinable() << endl;
	}
	pthread_join(t1.native_handle(), nullptr);
	pthread_join(t2.native_handle(), nullptr);
	// t2.join();
	cout << "main sleep" << endl;
	std::this_thread::sleep_for(chrono::seconds(1));
	cout << "End of main" << endl;
	
	return 0;
}
