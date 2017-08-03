#include <stdio.h>


void push(int *stack,int *top, int data){

	stack[++(*top)] = data;
}

int pop(int *stack, int *top){

	return stack[(*top)++];
}

int main(int argc, char const *argv[])
{
	int stack[10] = {0};
	int top = -1;
	int i;
	push(stack,&top, 5);
	push(stack,&top, 6);
	push(stack,&top, 7);
	push(stack,&top, 4);
	printf("The array: ");
	for (i = 0; i < 10; ++i)
	{
		if (stack[i] != 0)
		{
			
			printf("%d ", stack[i]);
		}
	}
	printf("\n");

	int val = pop(stack,&top);
	printf("Poped val: %d\n",val);

	return 0;
}