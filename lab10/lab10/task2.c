#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int main(){ 
	pid_t cpid = fork(); 
	if (cpid ==0){ 
		for(;;){ 
			printf("I am child in an infinite loop\n"); 
			sleep(1); 
		} 
	} 
	else{ 
		sleep(5); 
		kill(cpid,SIGINT); 
		printf("I have killed my child... Bye\n"); 
		_exit(0); 
	} 
	return 0;
}
