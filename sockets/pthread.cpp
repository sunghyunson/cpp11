#include <pthread.h>
#include <iostream>

using namespace std;

pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

int sum = 0;
int sum1 = 0;

void* threadRoutine(void* arg)
{
	int i;
	pthread_mutex_lock(&counter_mutex);

	for (i = 0; i < 1000000; i++)
	{
		sum++;
	}

	pthread_mutex_unlock(&counter_mutex);

	return NULL;
}

void* threadRoutine_no_mutex(void* arg)
{
	for (int i = 0; i < 1000000; i++)
	{
		sum1++;
	}

	return NULL;
}

int main()
{
	pthread_t threadID1;
	pthread_t threadID2;
	pthread_t threadID3;
	pthread_t threadID4;

	pthread_create(&threadID1, NULL, threadRoutine, NULL);
	pthread_create(&threadID2, NULL, threadRoutine, NULL);

	pthread_create(&threadID3, NULL, threadRoutine_no_mutex, NULL);
	pthread_create(&threadID4, NULL, threadRoutine_no_mutex, NULL);

	pthread_join(threadID1, NULL);
	pthread_join(threadID2, NULL);
	pthread_join(threadID3, NULL);
	pthread_join(threadID4, NULL);

	cout << "Using mutex: " << sum << endl;
	cout << "Not using mutex: " << sum1 << endl;
}