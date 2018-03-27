#include<stdio.h>
#include <stdlib.h>
int main()
{
	int size = 10;
	int *arr = (int*) malloc (sizeof(int) * size);
	
	int i = 0;
	int j = 1;
	for (i; i < size; i++)
	{
		arr[i] = j++;
	}
	i = 0;
	for (i; i < size; i++)
	{
		printf("Array is : %d", arr[i]);
		printf("\n");
	}
	
	int newsize = 2 * size;
	int * nptr = (int*) realloc (arr , sizeof(int)*newsize); 
	int k = 0;
	j = 1;
	i = 0;
	for (i; i < newsize; i++)
	{
		nptr[i] = j++;
	}
	i = 0;
	for (i; i < newsize; i++)
	{
		printf("New Array is : %d", nptr[i]);
		printf("\n");
	}
	free(nptr);
	return 0;
}
