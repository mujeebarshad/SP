#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> 
int main(int argc, char * argv[])
{	
	  char buff[256];
	  int fd = 1;
	  if(argc > 1)
	  {
		close(1);
		fd = open (argv[1],O_WRONLY| O_CREAT, 0777);
	  }
	 
	  int fd1 = open ("f4.txt", O_RDONLY); 
	  int n; 
	  printf("HI /mujeeb :)");
	  for(;;)
	  { 
		  n = read (fd1, buff, 255); 
		  if (n <= 0){ 
			  return 0;
		  }
		 
		write(fd, buff, n);
	  }

	   return 0; 

}


