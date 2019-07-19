#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void* t_function(void* data)
{
	int id;
	int i = 0;
	id = *((int*)data);

	while (1)
	{
		printf("%d : %d\n", id, i);
		i++;
		sleep(1);
	}
}


int main()
{
	pthread_t thread[2];
	int thr_id;
	int status;
	int a = 1;
	int b = 2;

	thr_id = pthread_create(&thread[0], NULL, t_function, (void*)&a);
	if (thr_id < 0)
	{
		perror("thread craete error : ");
		exit(0);
	}

	thr_id = pthread_create(&thread[1], NULL, t_function, (void*)&b);
	if (thr_id < 0)
	{
		perror("thread craete error : ");
		exit(0);
	}

	pthread_join(thread[0], (void**)&status);
	pthread_join(thread[1], (void**)&status);
	printf("end\n");

	return 0;
}