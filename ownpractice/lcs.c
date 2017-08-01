#include "stdio.h"


int lcs(int p[],int,int q[],int);


int main(int argc, char const *argv[])
{
	

	int x[4] = {4,5,2,7};
	int y[2] = {4,3};

	int length = lcs(x,0,y,0);
	printf("Lcs length: %d\n", length);

	return 0;
}

int lcs(int *a,int i,int *b,int j){
	if(i == 4 || j == 2) return 0;
	else if (a[i] == b[j])	
	{
		return 1 + lcs(a,i+1,b,j+1);
	}
	else{
		int p = lcs(a,i+1,b,j);
		int q = lcs(a,i,b,j+1);
		if (p > q)
		{
			return p;
		}else{
			return q;
		}
	}
}