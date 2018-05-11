#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
int main()
{ 
	char buff[1024]; 
	close(2);
	int fd1 = open ("srap", O_RDONLY); 
	int fd2 = dup(fd1); 
	int fd3 = open("errorandoutput.txt", O_CREAT|O_WRONLY, 0777);
	if(fd2 < 0)
	{
		
		//close(1);
		close(fd1);
		close(fd2);
		dup2(2,fd3);
		perror("Error!");
		return 0;
	}
	
		int n; 	
		for(;;)
		{ 
			n = read (fd2, buff, 1023); 
			if (n <= 0)
			{ 
				close(fd1); 
				close(fd2); 
				return 0; 
			} 
			write(fd3, buff, n); 
		}
		//end of for loop return 0;
	
		//end of for loop return 0;
} 

