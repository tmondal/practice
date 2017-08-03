#include <stdio.h>
#include <stdlib.h>


struct arraystack
{
	int top;
	int capacity;
	int *actualarray;
};

struct arraystack *createstack(){
	struct arraystack *stack = (struct arraystack *)malloc(sizeof(struct arraystack));
	stack->top = -1;
	stack->capacity = 10;
	stack->actualarray = (int *)malloc(sizeof(int)*stack->capacity);
}

int main(int argc, char const *argv[])
{
	struct arraystack *stack;
	stack = createstack();
	push(stack,8);
	push(stack,7);
	push(stack,3);

	

	return 0;
}