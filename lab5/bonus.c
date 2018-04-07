#include<stdio.h>
#include<unistd.h>
#include <stdlib.h> 

int mysystem(char*);
int main()
{ 
	printf("Running ls command using mysystem\n");
	mysystem("ls"); 
	printf("\nDone... Bye\n"); 
	exit(0); 
} 
int mysystem(char * cmd)
{ 
	int status; 
	pid_t cpid; 
	cpid = fork(); 
	switch (cpid)
	{ 
		case -1: perror("fork failed"); 
			return -1; 
		case 0: execl("/bin/bash","mybash","-c",cmd,'\0'); 
			_exit(127); 
		default: waitpid(cpid, &status, 0); 
		return status; 
	 } 
}

