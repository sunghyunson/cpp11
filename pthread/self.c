#include <pthread.h>
#include <stdio.h>

void* func(void* a)
{
	pthread_t id;
	id = pthread_self();
	printf("self -> %ld\n", id);
}

int main()
{
	pthread_t p_thread;
	pthread_create(&p_thread, NULL, func, (void*)NULL);
	printf("%d\n", p_thread);
	pthread_create(&p_thread, NULL, func, (void*)NULL);
	printf("%d\n", p_thread);

	return 1;
}