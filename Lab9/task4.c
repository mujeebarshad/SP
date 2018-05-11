#include <fcntl.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
int main(int argc, char* argv[])
{ 
	int i; 
	struct stat buf; 
	char * ptr; 
	if(argc != 2){ 
		fprintf(stderr, "Incorrect number of arguments\n"); 
		exit(1); 
		} 
	if (lstat(argv[1], &buf)<0)
	{ 
		perror("Error in lstat"); 
		exit(1); 
	} 
	printf("%s",argv[1]); 
	if (S_ISREG(buf.st_mode)) 
	{
		ptr = " is a regular file\n";
		printf(ptr);
		printf("INODE : %d\n", buf.st_ino);
		printf("Access Time : %d\n",buf.st_atime );
		printf("Modified Time : %d\n",buf.st_mtime );
		printf("Size  : %d\n",buf.st_size );  
	}
	else if (S_ISDIR(buf.st_mode)) 
	{
		ptr = " is a directory\n"; 
		printf(ptr);
		printf("User ID : %d\n",buf.st_uid );
	}
	else 
		ptr = " have unknown mode"; 
	//printf("%s\n",ptr);
	
	return 0;
	 } 
