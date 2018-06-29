#include<stdio.h>
#include<signal.h>
void myhandler(int signum){ 
	switch(signum){ 
		case 2: //SIGINT 
			printf("\nHey, I got SIGINT: %d\n\n",signum); 
			break; 
		case 3: //SIGQUIT
			printf("\nHey, I got SIGQUIT: %d\n\n",signum); 
			break; 
		case 20: //SIGTSTP
			printf("\nHey, I got SIGTSTP: %d\n\n",signum); 
			break; 
		case 8: //SIGFPE
			printf("\nHey, I got SIGFPE: %d\n\n",signum); 
			break; 
		case 9: //SIGKILL
			printf("\nHey, I got SIGKILL: %d\n\n",signum); 
			break; 
		case 19: //SIGHUP
			printf("\nHey, I got SIGHUP: %d\n\n",signum); 
			break; 
	}
}
int main() 
{ 	
	signal(SIGINT, myhandler); 
	signal(SIGHUP, myhandler); 
	signal(SIGQUIT, myhandler); 
	signal(SIGTSTP, myhandler); 
	signal(SIGFPE, myhandler); 
	signal(SIGKILL, myhandler); 
 
	while(1) { 
		printf("I am in an infinite loop!\n"); 
		sleep(1); 
	} 
	return 0;
}
