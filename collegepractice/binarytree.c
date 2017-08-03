#include <stdio.h>
#include <stdlib.h>


struct binarytreenode
{
	int data;
	struct binarytreenode *left;
	struct binarytreenode *right;
};

struct stack
{
	struct stack *next;
	struct binarytreenode *treenode;	
};

struct binarytreenode *createnewnode(data){
	printf("Node created.\n");
	struct binarytreenode *node = (struct binarytreenode *)malloc(sizeof(struct binarytreenode));
	if (node)
	{
		node->data = data;
		node->left = NULL;
		node->right = NULL;
	}else{
		printf("Memory error!\n");
		getchar();
		exit(0);
	}

	return node;
}

void preordertraversalrecursive(struct binarytreenode *root){
	if(root != NULL){
		printf("%d\n", root->data);
		preordertraversalrecursive(root->left);
		preordertraversalrecursive(root->right);
	}
}

void push(struct stack **headtostack,struct binarytreenode *treenode){

	// create a stack type node
	struct stack *newnode = (struct stack *)malloc(sizeof(struct stack));
	if (newnode == NULL)
	{
		printf("Error!!\n");
		getchar();
		exit(0);
	}
	newnode->treenode = treenode;
	newnode->next = (*headtostack);
	(*headtostack) = newnode;
}

struct binarytreenode *pop(struct stack **headtostack){
	struct stack *top;
	struct binarytreenode *returnnode;

	if (isempty(*headtostack))
	{
		printf("Stack underflow!\n");
		getchar();
		exit(0);
	}

	top = *headtostack;
	returnnode = (*headtostack)->treenode;

	// i was wiriting "headtostack = &(top->next)" think it
	*headtostack = top->next;
	free(top);
	return returnnode;
}

int isempty(struct stack *stackbase){
	if (stackbase == NULL)
	{
		return 1;
	}else{
		return 0;
	}
}

void preordertraversaliterative(struct binarytreenode *root){
	
	// initialize the stack
	struct stack *treenodestack = NULL;

	while(1){

		while(root != NULL){
			printf("%d\n", root->data);
			push(&treenodestack,root);
			root = root->left;
		}
		if (isempty(treenodestack))
		{
			break;
		}
		root = pop(&treenodestack);
		root = root->right;
	}
}

int main(int argc, char const *argv[])
{
	// create root 
	struct binarytreenode *root = createnewnode(1);
	
	// Add left&right node to the root
	root->left = createnewnode(5);
	root->right = createnewnode(7);
	root->left->left = createnewnode(4);
	root->left->right = createnewnode(9);


	// preordertraversalrecursive
	printf("Recursive traversal: \n");
	preordertraversalrecursive(root);

	//preordertraversaliterative
	printf("Iterative traversal: \n");
	preordertraversaliterative(root);
	return 0;
}