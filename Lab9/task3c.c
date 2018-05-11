#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
int main()
{ 
	char buff[1024]; 
	dup(2,1);
	int fd1 = open ("f11.txt", O_RDONLY); 
	int fd2 = dup(fd1); 
	int fd3 = open("f2.txt", O_APPEND|O_WRONLY);
	if(fd2 < 0)
	{
		
		close(1);
		//close(fd1);
		close(fd3);
		dup2(2,fd2);
		perror("Error!");
		return 0;
	}
	
		int n; 	
		for(;;)
		{ 
			n = read (fd2, buff, 1023); 
			if (n <= 0)
			{ 
				close(1);
				close(fd1); 
				close(fd2); 
				return 0; 
			} 
			write(fd3, buff, n); 
		}
		//end of for loop return 0;
	
		
} 



