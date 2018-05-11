#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
int main()
{ 
	char buff[1024]; 
	int fd1 = open ("/etc/passwd", O_RDONLY); 
	int fd2 = dup(fd1); 
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
		write(1, buff, n); }
		//end of for loop return 0;
	} 

