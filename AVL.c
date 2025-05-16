#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	int height;
	struct node *left;
	struct node *right;
};

int height(struct node *N){
	if(N == NULL){
		return 0;
	}
return N->height;
}

int max(int a, int b){
	if(a > b){
		return a;
	}else{
		return b;
	}
}

struct node *rightRotate(struct node *a){
	struct node *b = a->left;
	
	a->left = b->right;
	b->right = a;
	
	a->height = max(height(a->left), height(a->right)) + 1;
	b->height = max(height(b->left), height(b->right)) + 1;
	
	return b;
}

struct node *leftRotate(struct node *a){
	struct node *b = a->right;
	
	a->right = b->left;
	b->left = a;
	
	a->height = max(height(a->left), height(a->right)) + 1;
	b->height = max(height(b->left), height(b->right)) + 1;
	
	return b;
}

int getBalance(struct node *N){
	if(N == NULL){
		return 0;
	}
	return height(N->left) - height(N->right);
}

struct node *newNode(int value){
	struct node *newnode = (struct node*)malloc(sizeof(struct node));
	newnode->value = value;
	newnode->left = newnode->right = NULL;
	newnode->height = 1;
return(newnode);
}

struct node *insertNode(struct node *root, int value){
	if(root == NULL){
		return (newNode(value));
	}
	
	if(value < root->value){
		root->left = insertNode(root->left, value);
	}else if(value > root->value){
		root->right = insertNode(root->right, value);
	}else{
		return(root);
	}
	return(root);
	
	//update balance factor
	root->height = 1 + max(height(root->left), height(root->right));
	int balance = getBalance(root);
	
	
	if(balance > 1 && value < root->left->value){
		return rightRotate(root);
	}
	
	
	if(balance < -1 && value > root->right->value){
		return leftRotate(root);
	}
	
	//LR
	if(balance > 1 && value > root->left->value){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	//RL
	if(balance < -1 && value < root->left->value){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
	
	return root;
}



struct node *succ(struct node *ptr){
	struct node *current = ptr;
	while(current->left != NULL){
		current = current->left;
	}
return(current);
}

struct node *deleteNode(struct node *root, int value){
	if(root == NULL){
		return(root);
	}
	
	if(value < root->value){
		root->left = deleteNode(root->left, value);
	}else if(value > root->value){
		root->right = deleteNode(root->right, value);
	}else{
		if((root->left == NULL) || (root->right == NULL)){
			struct node *temp;
			if(root->left != NULL){
				temp = root->left;
			}else{
				temp = root->right;
			}
			
			if(temp == NULL){
				temp = root;
				root = NULL;
			}else{
				*root = *temp;
				free(temp);
			}
		}else{
			struct node *temp = succ(root->right);
			root->value = temp->value;
			root->right = deleteNode(root->right, temp->value);
		}
	}
	
	if(root == NULL){
		return root;
	}
	
	//update balance
	//update height
	root->height = max(height(root->left), height(root->right));
	int balance = getBalance(root);
	
	if(balance > 1 && getBalance(root->left) >=0 ){
		return rightRotate(root);
	}
	
	if(balance < -1 && getBalance(root->right) <= 0){
		return leftRotate(root);
	}
	
	if(balance > 1 && getBalance(root->left) < 0){
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
	
	if(balance < -1 && getBalance(root->right) > 0){
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}
return root;
}

struct node *inOrder(struct node *root){
	if(root != NULL){
		printf("%d ", root->value);
		inOrder(root->left);
		inOrder(root->right);
	}
}

int main(){
	struct node *root = NULL;
	root = insertNode(root, 5);
	root = insertNode(root, -1);
	root = insertNode(root, 4);
	inOrder(root);
	printf("\n");
return 0;
}
