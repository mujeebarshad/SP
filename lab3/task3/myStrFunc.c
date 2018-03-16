#include<stdio.h>

int isPalindrome(char *arr, int size)
{
	int i = 0;
	int j = size-1;
	for(i;i<size;i++)
	{
		if(arr[i] != arr[j])
		{
			printf("Number is not Palindrome!\n");
			return -1;
		}
		j--;
	}
	
	printf("Number is palindrome!\n");
	return 1;
	
	
}
