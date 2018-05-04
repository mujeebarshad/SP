//Actually Task 1
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
int main(int argc, char * argv[])
{ 
	int n;
	char buff[1024]; 
	int fd = open(argv[1] ,O_RDONLY,0777); 
	int fd1 = open(argv[2] ,O_CREAT|O_RDWR,0777); 
	if (fd == -1)
	{ 
		perror("Error in creating file"); 
		exit(1); 
	}  
	for(;;)
	{ 
		n = read (fd, buff, 1023); 
		if (n<=0)
		{ 
			perror("Error in reading source file."); 
			exit(1); 
		} 
		write(fd1, buff, n); 
		unlink(argv[1]);
		close(fd); 
		return 0; 
	}
}


