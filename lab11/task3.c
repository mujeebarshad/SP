#include <stdio.h> 
#include <stdlib.h> //exit() 
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#include <unistd.h> 

int main(){ 
	int fd[2]; 
	int res = pipe(fd);
	printf("res : %d",res); 
	pid_t cpid = fork(); 
	if (cpid == 0) { 
		int fd1[2]; 	
		pipe(fd1); 
		pid_t ccpid = fork(); 
		if (ccpid == 0) {
			close(1);
			dup(fd1[1]);
			close(fd1[0]);
			execlp("man", "man", "ls", NULL);		
		}
		else{
			close(0);  
			dup(fd1[0]);
			close(fd1[1]);
			close(1);
			dup(fd[1]);
			//close(fd[1]);
			wait(NULL);
			execlp("grep","grep", "ls", NULL); 
		}
		
	} 
	else{ 
		close(0);
		dup(fd[0]);
		close(fd[1]);
		wait(NULL);
		execlp("wc","wc","-l", NULL);
	}
} 

