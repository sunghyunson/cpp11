#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void Smart(int);

int main()
{
	struct sigaction st_Act;
	st_Act.sa_handler = Smart;
	sigfillset(&st_Act.sa_mask);
	st_Act.sa_flags = 0;

	sigaction(SIGALRM, &st_Act, 0);
	alarm(5);

	while (1)
	{
		printf("hi~ 'q' = quit\n");
		if ('q' == getchar())
		{
			break;
		}
	}
	return 0;
}

void Smart(int a)
{
	printf("5초 지났음둥\n");
	alarm(5);
	return;
}