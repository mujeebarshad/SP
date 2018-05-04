#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> 
int main()
{	
	  char buff[256];
	  int fd = open ("newfile.txt", O_WRONLY);
	  int fd1 = open ("f1.txt", O_RDONLY); 
	  int n; 
	  for(;;)
	  { 
		  n = read (fd1, buff, 255); 
		  if (n <= 0){ 
			  close(fd);
			  return 0;
		  }
		 write(fd, buff, n);
	  }
	   return 0; 

}

