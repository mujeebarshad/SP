#include<stdio.h>

int isEqual(int x, int y)
{
	if(x == y)
	{
		printf("Numbers are Equal!\n");
		return 1;
	}
	else
	{
		printf("Numbers are not Equal!\n");	
		return -1;
	}
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
