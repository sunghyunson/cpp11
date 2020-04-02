#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

void* ping(void*);
void* pong(void*);

pthread_mutex_t sync_mutex;
pthread_cond_t sync_cond;

pthread_mutex_t gmutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t gcond = PTHREAD_COND_INITIALIZER;


int main()
{
	vector<void* (*)(void*)> thread_list;
	vector<pthread_t> tident(10);
	int thresult;
	int status;

	pthread_mutex_init(&sync_mutex, NULL);
	pthread_cond_init(&sync_cond, NULL);

	thread_list.push_back(pong);
	thread_list.push_back(ping);

	for (int i = 0; i < thread_list.size(); i++)
	{
		pthread_mutex_lock(&sync_mutex);
		if (pthread_create(&tident[i], NULL, thread_list[i], (void*)NULL) < 0)
		{
			perror("error");
			exit(0);
		}
		pthread_cond_wait(&sync_cond, &sync_mutex);
		pthread_mutex_unlock(&sync_mutex);
	}

	for (int i = 0; i < tident.size(); i++)
	{
		pthread_join(tident[i], (void**)&status);
	}

	pthread_cond_destroy(&sync_cond);
	pthread_mutex_destroy(&sync_mutex);
	pthread_cond_destroy(&gcond);
	pthread_mutex_destroy(&gmutex);

	return 0;
}

void* ping(void* data)
{
	int i = 0;
	printf("** ping is open\n");
	pthread_mutex_lock(&sync_mutex);
	printf("** ping is entered\n");
	pthread_cond_signal(&sync_cond);
	pthread_mutex_unlock(&sync_mutex);

	while (1)
	{
		pthread_mutex_lock(&gmutex);
		printf("** ping -- lock mutex\n");
		printf("** %d : ping\n", i);
		pthread_cond_signal(&gcond);
		pthread_cond_wait(&gcond, &gmutex);
		printf("** ping -- unlock mutex\n");
		pthread_mutex_unlock(&gmutex);
		printf("** ping wait & unlock\n");
		usleep(random() % 1000000);
		i++;
		if (i > 2)
		{
			break;
		}
	}
}

void* pong(void* data)
{
	int i = 0;
	printf("pong is open\n");
	// pthread_mutex_lock(&sync_mutex);
	printf("pong is sleeping...\n");
	sleep(3);
	pthread_cond_signal(&sync_cond);
	pthread_mutex_unlock(&sync_mutex);

	while (1)
	{
		// pthread_mutex_lock(&gmutex);
		printf("pong -- lock mutex\n");
		pthread_cond_wait(&gcond, &gmutex);
		printf("%d : pong\n", i);
		pthread_cond_signal(&gcond);
		printf("pong -- unlock mutex\n");
		pthread_mutex_unlock(&gmutex);
		i++;
		if (i > 2)
			break;
	}
}
