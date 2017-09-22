#include"program.h"

int main(int argc, char *argv[])
{
	pid_t child1,child2,pid1,pid2;
	int status1,status2;
	
	printf("Parent:: pid=%d\n",getpid());
	
	child1=fork();
	
	if(child1 == 0)
	{
		printf("Child1:: Created\n");
		printf("Child1:: pid=%d\n",getpid());
		printf("Child1:: Sleeping for 5 seconds.\n");
		sleep(5);
		printf("Child1:: Sleep completed\n");
		printf("Child1:: Terminating\n");
	}
	else
	{
		child2 = fork();
		if(child2 == 0)
		{
			printf("Child2:: Created\n");
			printf("Child2:: pid=%d\n",getpid());
			printf("Child2:: Sleeping for 5 seconds.\n");
			sleep(5);
			printf("Child2:: Sleep completed\n");
			printf("Child2:: Terminating\n");
		}
		else
		{
			printf("Parent:: Before wait.\n");
			pid1 = wait(&status1);
			pid2 = wait(&status2);
			printf("Parent:: Child process with pid: %ld terminated with status: %d\n",pid1,status1);	
			printf("Parent:: Child process with pid: %ld terminated with status: %d\n",pid2,status2);	
			printf("Parent:: terminating\n");			
		}
	}
	

}

