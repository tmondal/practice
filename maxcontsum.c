#include <stdio.h>


void bruteforce(int *, int);
// void dynamic(int *, int);

int main(int argc, char const *argv[])
{
	
	int arr[7] = {2,11,-14,13,5,-20,5};

	bruteforce(arr,7);
	// dynamic(arr,7);

	return 0;
}

void bruteforce(int *x, int m){

	int i,j,sum = 0,max = 0,newmax = 0,start = 0,newstart = 0,end = 0;
	for (i = 0; i < m; ++i)
	{
		sum += x[i];
		if (sum <= 0)
		{
			newstart = i + 1;
			sum = 0;
		}else{
			newmax = sum;
		}

		if (max < newmax)
		{
			start = newstart;
			end = i;
			max = newmax;
		}
	}
	printf("\nMax cont. sum: %d\n", max);
	for (i = start; i <= end; ++i)
	{
		printf("%d ", x[i]);
	}
	printf("\n");
}

void dynamic(int *y, int n){

	int table[n];
	int i,max = 0;
	if (y[0] > 0)
	{
		table[0] = y[0];
	}else{
		table[0] = 0;
	}
	for (i = 1; i < n; ++i)
	{
		if (table[i-1] + y[i] > 0)
		{
			table[i] = table[i-1] + y[i];
		}else{
			table[i] = 0;
		}
	}

	for (i = 0; i < n; ++i)
	{
		if (max < table[i])
		{
			max = table[i];
		}
	}

	printf("Length: %d\n", max);
}

