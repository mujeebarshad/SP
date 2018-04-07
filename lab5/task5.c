#include<stdio.h>
#include<unistd.h>
#include <stdlib.h> 
int main()
{
	int i = fork();
	int status;
	if (i == -1){
		printf("Fork failed\n");
		exit(1);
	}
	if(i==0)
	{	
		exit(-1);
		printf("Child PID is %d\n", (long)getpid());
		printf("Child PPID is %d\n", (long)getppid());
	}
	else{
		wait(&status);
		if(WIFEXITED(status)){
			printf("Child exit status = %d\n", WEXITSTATUS(status)); 
		}
		printf("Parent PID is %d\n", (long)getpid());
		printf("Parent PPID is %d\n", (long)getppid());	
	}
	return 0;
}
