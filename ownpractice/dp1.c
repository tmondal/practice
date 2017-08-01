#include <stdio.h>
#define NIL -1
#define MAX 10

int arr[MAX];
int tdfib(int);
int btfib(int);
void initialize();

int main(int argc, char const *argv[])
{
	int n,i;
	initialize();
	for (i = 0; i < 5; ++i)
	{
		printf("bottom up : %d\n", btfib(i));
	}
	return 0;
}

void initialize(){
	int i;
	for (i = 0; i < MAX; ++i)
	{
		arr[i] = NIL;
	}
}


// Top down dp approach(modified recursive)
int fib(n){
	if (arr[n] != NIL)
	{
		return arr[n];
	}else{
		if (n <= 1)
		{
			return n;
		}else{
			arr[n] = fib(n-1) + fib(n-2);
		}
	}
	return arr[n];
}

// Botton up approach(no recursion or iterative)
int btfib(n){
	int i;
	arr[0] = 0;
	arr[1] = 1;
	for (i = 2; i <= n; ++i)
	{
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	return arr[n];
}




