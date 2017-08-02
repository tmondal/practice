#include <stdio.h>
#include <stdlib.h>


struct queue
{
	int data;
	struct queue *next;
};

void enqueue(struct queue **front,int data){

	struct queue *newnode = (struct queue *)malloc(sizeof(struct queue));
	struct queue *temp;
	temp = *front;

	if (newnode == NULL)
	{
		printf("Memory error!\n");
		getchar();
		exit(0);

	}
	if (temp)
	{
		while(temp->next != NULL){
			temp = temp->next;
		}
		printf("Here\n");
		temp->next = newnode;
	}else{
		*front = newnode;
	}
	newnode->data = data;
	newnode->next = NULL;
}

int dequeue(struct queue **q){

	int returndata = (*q)->data;
	*q = (*q)->next;
	return returndata;
}

void printqueue(struct queue **front){

	struct queue *temp = *front;
	printf("Queue: ");
	while(temp){
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(int argc, char const *argv[])
{
	struct queue *Queue = NULL;

	enqueue(&Queue,5);
	enqueue(&Queue,7);
	enqueue(&Queue,6);
	enqueue(&Queue,8);
	enqueue(&Queue,3);
	enqueue(&Queue,4);
	
	printqueue(&Queue);

	int val = dequeue(&Queue);
	printf("Dequeued value: %d\n", val);
	return 0;
}