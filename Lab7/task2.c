#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
int main(int argc, char * argv[])
{ 
	int n;
	char buff[1024]; 
	int fd = open(argv[1] ,O_CREAT|O_RDWR,0777); 
	if (fd == -1)
	{ 
		perror("Error in creating file"); 
		exit(1); 
	} 
	int fd1 = open ("/etc/shadow", O_RDONLY); 
	for(;;)
	{ 
		n = read (fd1, buff, 1023); 
		if (n<=0)
		{ 
			perror("Error in reading source file."); 
			exit(1); 
		} 
		write(fd, buff, n); 
		
		close(fd); 
		return 0; 
	}
}
