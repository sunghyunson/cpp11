#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// NOTE
// int pthread_cleanup_push(void (*routine)(void*), void* arg);

char* mydata;
void cleanup(void*);

void* t_function(void* data)
{
	int num = *((int*)data);
	int i = 0;
	int a = 1;
	// set cleanup handler as clenaup
	pthread_cleanup_push(cleanup, (void*)&a);

	mydata = (char*)malloc(1000);

	while (1)
	{
		if (i == 3)
		{
			pthread_exit(0);
			return 1;
		}
		printf("loop %d\n", i);
		i++;
		sleep(1);
	}
	printf("pop?\n");
	pthread_cleanup_pop(0);
}

int main()
{
	pthread_t p_thread;
	int thr_id;
	int status;
	int a = 100;

	printf("Before Thread\n");
	thr_id = pthread_create(&p_thread, NULL, t_function, (void*)&a);
	if (thr_id < 0)
	{
		perror("thread create error");
		exit(0);
	}

	pthread_join(p_thread, (void**)&status);
	return 0;
}

//cleanup handler
void cleanup(void* myarg)
{
	printf("thread is clean up\n");
	printf("resource free\n");
	free(mydata);
}