#include <stdio.h>


int main(int argc, char const *argv[])
{
	int row,col;
	int i,j,n,k,l;
	
	printf("Enter no of row: ");
	scanf("%d",&row);
	printf("Enter no of col: ");
	scanf("%d", &col);

	int rowstart = 0,rowend = row -1 ,colstart = 0,colend = col - 1;
	int matrix[row][col];

	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			printf("Pos: (%d,%d): ", i,j);
			scanf("%d",&matrix[i][j]);
		}
	}

	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	while (rowstart <= rowend && colstart <= colend)
	{
		for (i = colstart; i <= colend; i++)
		{
			printf("%d ", matrix[rowstart][i]);	
		}
		for (j = rowstart+1; j <= rowend; j++)
		{
			printf("%d ", matrix[j][colend]);
		}
		for (k = colend-1; k >= colstart; k--)
		{
			printf("%d ", matrix[rowend][k]);
		}

		for (l = rowend-1; l >= rowstart+1; l--)
		{
			printf("%d ", matrix[l][colstart]);
		}
		rowstart ++;
		colstart ++;
		rowend --;
		colend --;
	}
	printf("\n");
	return 0;
}