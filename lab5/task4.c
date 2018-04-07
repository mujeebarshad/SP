#include<stdio.h>
#include<unistd.h>
int main()
{
	int i = fork();
	if (i == -1){
		printf("Fork failed\n");
		exit(1);
	}
	if(i==0)
	{	
		printf("Child PID is %d\n", (long)getpid());
		printf("Child PPID is %d\n", (long)getppid());
	}
	else{
		wait(null);
		printf("Parent PID is %d\n", (long)getpid());
		printf("Parent PPID is %d\n", (long)getppid());	
	}
	return 0;
}
