#include<stdlib.h>
#include<stdio.h>
#include<setjmp.h>
int counter=0;
static jmp_buf envbuf;
void func();
int main()
{ 
	int i = 0; 
	for(i; i <5; i++)
	{
	printf("This is main()\n"); 
	if (counter == 0 && (i = setjmp(envbuf)) == 0)
	{ 
		first(); 
	}
	func();
	 
	}
	return 0;  
}
	void func()
	{ 
		printf("This is Fun()\n"); 
		printf("Value of Counter: %d", counter);
		printf("\n");
		counter++; 
	}
	void first()
	{ 
		printf("This is first()\n"); 
		printf("Value of Counter: %d", counter);
		printf("\n");
		counter++; 
	}
