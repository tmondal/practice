#include <stdio.h>
#include <stdlib.h>


struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
};


struct tree *createnewnode(int data){

	// allocate space
	struct tree *newnode = (struct tree *)malloc(sizeof(struct tree));
	if (newnode == NULL)
	{
		printf("Memory error!\n");
		getchar();
		exit(0);
	}
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

// array implementation of queue
struct tree **createqueue(int *front, int *rear){

	struct tree **temp = (struct tree **)malloc(sizeof(struct tree)*10);
	*front = *rear = 0;

	return temp;
}

void enqueue(struct tree **head, int *rear,struct tree *data){

	head[(*rear)++] = data;
}

struct tree *dequeue(struct tree **head,int *front){

	return head[(*front)++];
}

void levelordertraversal(struct tree *root){

	struct tree *temp;
	int front,rear;
	struct tree **Queue = createqueue(&front,&rear);
	temp = root;

	if (root == NULL)
	{
		printf("No elements in the tree!\n");
		getchar();
		exit(0);
	}
	while(temp){
		printf("%d\n", temp->data);
		if (temp->left)
		{
			enqueue(Queue,&rear,temp->left);
		}
		if (temp->right)
		{
			enqueue(Queue,&rear,temp->right);
		}
		temp = dequeue(Queue,&front);
	}
}

int main(int argc, char const *argv[])
{
	
	struct tree *root;
	root = createnewnode(1);
	root->left = createnewnode(2);
	root->right = createnewnode(3);
	root->left->left = createnewnode(4);
	root->left->right = createnewnode(5);

	printf("Level order traversal: \n");
	levelordertraversal(root);

	return 0;
}