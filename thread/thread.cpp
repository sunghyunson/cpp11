#include <iostream>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <mutex>

using namespace std;

mutex mutex_lock;

void *t_function(void *data)
{
	int num = *((int *)data);
	mutex_lock.lock();
	cout << "num is : " << num << endl;
	// pthread_detach(pthread_self());
	cout << num << " : Thread Start\n";
	// pthread_exit((void*)num);
	mutex_lock.unlock();

	int i = 0;
	while (true)
	{
		sleep(1);
		i++;
		mutex_lock.lock();
		cout << num << " : good morning" << endl;
		mutex_lock.unlock();
		if (i > 5)
		{
			// pthread_exit((void*)num);
			break;
		}
	}
	if (num == 100)
	{
		num = 101;
	}
	else if (num == 200)
	{
		num = 201;
	}
	else
	{
		num = 5;
	}
	cout << "Thread end\n";
	return (void *)(num);
}

void callthread(pthread_t &p_thread, int &value)
{
	int thr_id1;

	cout << "Before Thread 1 : " << value << endl;
	thr_id1 = pthread_create(&p_thread, NULL, t_function, (void *)&value);
	if (thr_id1 < 0)
	{
		cerr << "thread create error : ";
		return;
	}
}

// void callthread2(pthread_t &p_thread)
// {
// 	int thr_id2;
// 	int b = 333;

// 	cout << "Before Thread 2 : " << b << endl;
// 	thr_id2 = pthread_create(&p_thread, NULL, t_function, (void *)&b);
// 	if (thr_id2 < 0)
// 	{
// 		cerr << "thread create error : ";
// 		return;
// 	}
// }

int main()
{
	cout << "thread\n";
	int result1;
	int result2;
	// int result;
	pthread_t p_thread1;
	pthread_t p_thread2;
	int a = 100;
	int *b;

	callthread(p_thread1, a);
	// sleep(2);
	callthread(p_thread2, b);
	// callthread2(p_thread2);

	// pthread_join(p_thread1, (void **)&result1);
	// cout << "result 1 : " << result1 << endl;
	// pthread_join(p_thread2, (void **)&result2);
	// cout << "result 2 : " << result2 << endl;

	// 식별번호 p_thread 를 가지는 쓰레드를 detach
	// 시켜준다.
	// pthread_detach(p_thread);
	cout << "Before Join\n";
	//sleep(3);
	// pthread_join(p_thread, (void**)&result);
	// cout << "After join : " << result << "\n";

	sleep(2);
	cout << "Finish Main\n";

	return 0;
}
