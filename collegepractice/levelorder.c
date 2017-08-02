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

void levelordertraversal(struct tree *root){

	struct tree *temp;
	struct queue *Queue = NULL;
	if (root == NULL)
	{
		printf("No elements in the tree!\n");
		getchar();
		exit(0);
	}
	enqueue(Queue,root);
	while(!isempty(Queue)){
		temp = dequeue(Queue);
		printf("%d\n", temp->data);
		if (temp->left)
		{
			enqueue(Queue,temp->left);
		}
		if (temp->right)
		{
			enqueue(Queue,temp->right);
		}
	}
}

int main(int argc, char const *argv[])
{
	
	struct tree *root;
	root = createnewnode(1);
	root->left = createnewnode(2);
	root->right = createnewnode(5);
	root->left->left = creanewnode(3);
	root->left->right = createnewnode(4);

	printf("Level order traversal: \n");
	levelordertraversal(root);

	return 0;
}