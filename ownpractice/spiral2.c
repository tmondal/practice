#include <stdio.h>
main()
{
	int i;
	int column_start = 0,column_end = 3,row_start = 0,row_end = 3;
	int a[4][4] = {{1,2,3,4},{12,13,14,5},{11,16,15,6},{10,9,8,7}};
	while(row_start<row_end && column_start<column_end)
	{
		for(i=column_start;i<column_end;i++)
			printf("%d ",a[row_start][i]);
		for(i=row_start;i<row_end;i++)
			printf("%d ",a[i][column_end]);
		for(i=column_end;i>column_start;i--)
			printf("%d ",a[row_end][i]);
		for(i=row_end;i>row_start;i--)
			printf("%d ",a[i][column_start]);
		row_start++;column_start++;row_end--;column_end--;
	}
	printf("\n");
}