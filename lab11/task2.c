#include <stdio.h> 
#include <stdlib.h>  
#include <string.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
#define SIZE 1024 
int main(){ 
	int fd1[2]; 
	int fd2[2]; 
	int rv1 = pipe(fd1); 
	int rv2 = pipe(fd2); 
//create a child process 
	pid_t cpid = fork(); 
//child code will read from fd1 and write into fd2 
	if (cpid == 0) { 
		close(fd1[1]); //close write end 
		close(fd2[0]); //close read end 
		char childbuff[SIZE]; 
		memset(childbuff, '\0',SIZE); 
		const char *msgfromchild = "I am child\n"; 
//child receives a message from parent 
		int n = read(fd1[0],childbuff,SIZE); 
		printf("Message received from parent: \n"); 
		write(1,childbuff,n); 
//child sends a message to parent 
		write(fd2[1],msgfromchild,strlen(msgfromchild)); 
		exit(0); 
	} 
//parent code will read from fd2 and write into fd1 
	else { 
	close(fd1[0]); 
	close(fd2[1]); 
	char parentbuff[SIZE]; 
	memset(parentbuff, '\0',SIZE); 
	const char * msgfromparent = "I am parent\n"; 
//parent sends a message to child 
	write(fd1[1], msgfromparent,strlen(msgfromparent)); 
//parent receives a message from child 
	int n = read(fd2[0],parentbuff,SIZE); 
	printf("Message received from child: \n"); 
	write(1,parentbuff,n); 
	wait(NULL); 
	exit(0); 
	} 
	return 0;
} 
