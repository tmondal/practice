#include "stdio.h"

int main(int argc, char const *argv[])
{

	int i,j,k,max = 0,maxpos,maxval = 0;
	int arr[5] = {4,5,2,7,3};
	int LIStable[5];
	int contribute[5];

	
	// Initialize the table with 1
	for (i = 0; i < 5; ++i)
	{
		LIStable[i] = 1;
		contribute[i] = i;
	}

	// finding LIS when LIS(i) implies LIS starting at A[0] and ending at A[i]
	// equation : LIS(i) = Max(j<i && A[j]<A[i]){LIS(j)} + 1
	for (i = 0; i < 5; ++i)
	{
		for (j = 0; j <= i; ++j)
		{	
			if (arr[j] < arr[i] && LIStable[i] < LIStable[j] + 1)
			{
				LIStable[i] = LIStable[j] + 1;
				contribute[i] = j; // track last contributor for printing purpose
			}
		}

	}

	// finding LIS when LIS(i) implies LIS starting at A[i] and ending at A[n]
	// equation : LIS(i) = Max(j>i && A[j]>A[i]){LIS(j)} + 1

	/*for (i = 4; i >= 0; i--){
		for (j = i+1;j < 5; j++){
			if (arr[j] > arr[i] && LIStable[i] < LIStable[j] + 1)
			{
				LIStable[i] = LIStable[j] + 1;
			}
		}
	}*/

	for (i = 0; i < 5; ++i)
	{
		printf("%d ", LIStable[i]);
	}
	for (i = 0; i < 5; ++i){
		if (max < LIStable[i])
		{
			max = LIStable[i];
			maxpos = i;
		}
	}


	printf("Max Length: %d\n", max);
	printf("Max pos: %d\n", maxpos);

	// 7's contributor 5 and 5's contributor 4(always track last contributor then its contributor and so on)
	while(contribute[maxpos] != maxpos)
	{
		printf("%d ",arr[maxpos]);
		maxpos = contribute[maxpos];
	}
	printf("%d\n",arr[maxpos]);

	return 0;
}