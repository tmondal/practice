#include <stdio.h>


int main(int argc, char const *argv[])
{
	int i,j,k,max=0;
	int a[6] = {4,5,2,7,3,8};
	int b[6],c[6];
	//lis(a,6);
	for(i=0;i<6;i++)
	{
		b[i] = 1;
		c[i] = i;
	}
	for(i=4;i>=0;i--)
	{
		for(j=i+1;j<6;j++)
		{
			if(a[i]<a[j] && b[i]<b[j]+1)
			{
				b[i] = b[j]+1;
				c[i] = j;
			}

		}
	}

	for(i=0;i<6;i++)
	{
		if(max < b[i])
		{
			max = b[i];
			k = i;
		}
	}
	printf("%d\n",b[k]);
	while(c[k] != k)
	{
		printf("%d ",a[k]);
		k = c[k];
	}
	printf("%d\n",a[k]);

	return 0;
}