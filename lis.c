#include <stdio.h>

#define MAX 5
int dplength[MAX];
int arr[5] = {4,5,2,7,3};
int val[5];
int maxval[5];

int lis(int);
void initialize();

int main(int argc, char const *argv[])
{
	int i,j,el,length,max = 0;
	initialize();

	// bruteforce method(O(n^2))
	for (i = 0; i < 5; ++i)
	{
		int length = 1;
		el = arr[i];
		val[i] = el;
		for (j = i; j < 4; ++j)
		{
			if (el < arr[j+1])
			{
				length ++;
				el = arr[j+1];
				val[j+1] = arr[j+1];
			}
		}
		if (length > max)
		{
			max = length;
			for (i = 0; i < 5; ++i)
			{
				maxval[i] = val[i];
			}
		}
	}
	for (i = 0; i < 5; ++i)
	{
		if (maxval[i] != -1)
		{
			printf("%d\n", maxval[i]);
		}
	}
	
	return 0;
}

void initialize(){
	int i;
	for (i = 0; i < 5; ++i)
	{
		val[i] = -1;
	}
	for (i = 0; i < 5; ++i)
	{
		maxval[i] = -1;
	}
}
