#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int a = 6;

int main()
{
	int N = 5;

	pid_t pid[N] = {-1, -1, -1, -1, -1}; /* process id */
	int childStatus;
	int i;

	for (i = 0; i < N; i++)
	{
		pid[i] = fork();
		if (pid[i] == 0)
		{
			printf("Now pid[%d] is die : %d\n", i, getpid());
			exit(100 + i);
		}
		// Create multiple child processes
	}

	for (i = 0; i < N; i++)
	{
		pid_t terminatedChild = wait(&childStatus);

		if (WIFEXITED(childStatus))
		{
			// The child process has termindated normally
			printf("Child %d has terminated with exit status %d\n", terminatedChild, WEXITSTATUS(childStatus));
		}
		else
		{
			printf("Child %d has terminated abnormally\n", terminatedChild);
		}
	}
}



int base()
{
	int b;
	int childStatus;
	pid_t pid;

	b = 88;

	printf("Befor fork\n");

	pid = fork();
	printf("This is pid value :: %d // %d\n", pid, getpid());
	if (pid == 0)
	{
		// child
		a++;
		b++;
		printf("This is the child number is %d %d // %d\n", a, b, getpid());
		sleep(3);
	}
	else
	{
		wait(&childStatus);
		printf("This is the parent number is %d %d // %d\n", a, b, getpid());
	}

	return 0;
}
