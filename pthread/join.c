#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void* t_function(void* data)
{
	int num = *((int*)data);
	printf("num %d\n", num);
	sleep(1);
	return (void*)(num * num);
}

int main()
{
	pthread_t p_thread;
	int thr_id;
	int status;
	int a = 100;

	thr_id = pthread_create(&p_thread, NULL, t_function, (void*)&a);
	if (thr_id < 0)
	{
		perror("thread create erro : ");
		exit(0);
	}

	pthread_join(p_thread, (void*)&status);
	printf("thread join : %d\n", status);

	return 0;
}