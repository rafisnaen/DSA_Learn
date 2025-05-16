#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
int main(){


struct tree{
	int value;
	struct tree *right;
	struct tree *left;
};

struct tree *root = NULL;

struct tree *insert(struct tree *root, int value){
	struct tree *newNode = (struct tree*)malloc(sizeof(struct tree));
	newNode->left = newNode->right = NULL;
	newNode->value = value;
	
	struct tree *curr = NULL;
	struct tree *parent = NULL;
	
	if(root == NULL){
		root = newNode;
		return root;
	}else{
		curr = root;
		while(curr != NULL){
			parent = curr;
			if(newNode->value < curr->value){
				curr = curr->left;
			}else{
				curr = curr->right;
			}
		}
	}
	
	if(newNode->value < parent->value){
		parent->left = newNode;
	}else{
		parent->right = newNode;
	}
	
return root;
}

void display(struct tree *root){
	if(root != NULL){
		printf("%d ", root->value);
		display(root->left);
		display(root->right);
	}
}


struct tree *delet(struct tree *root, int value){
	
	struct tree *curr = NULL, *parent = NULL;
	
	curr = root;
	while(curr != NULL && curr->value != value){
		parent = curr;
		if(value < curr->value){
			curr = curr->left;
		}else{
			curr = curr->right;
		}
	}
	
	printf("%d\n", curr->value);
	
	if(curr->left == NULL && curr->right == NULL){
        if(parent == NULL){ 
            free(curr);
            return NULL;
        }
		if(parent->left == curr){
        	parent->left = NULL;
		}else{
        	parent->right = NULL;
		}
		free(curr);
    }
    
    
	else if(curr->left == NULL){
		if(parent == NULL){
			root = curr->right;
			curr->right = NULL;
			free(curr);
			return root;
		}else{
			if(parent->left == curr){
				parent->left = curr->right;
			}else{
				parent->right = curr->right;
			}
			free(curr);
		}
	}
	
	
	else if(curr->right == NULL){
		if(parent == NULL){
			root = curr->left;
			curr->left = NULL;
			free(curr);
			return root;
		}else{
			if(parent->left == curr){
				parent->left = curr->left;
			}else{
				parent->right = curr->right;
			}
			free(curr);
		}
	}
	
	else{
		struct tree *temp = curr->right;
		
		while(temp->left != NULL){
			temp = temp->left;
		}
		curr->value = temp->value;
		curr->right = delet(curr->right, temp->value);
	}
	return root;
}



int main(){
	int nilai_ganjil[] = {53, 31, 77, 19, 41, 65, 89, 23, 47, 59, 71, 83, 67, 61, 97};
	int i;
	for(i = 0; i < 15; i++){
		root = insert(root, nilai_ganjil[i]);
	}
	display(root);
	int value;
	printf("\n>> ");
	scanf("%d", &value);
	root = delet(root, value);
	display(root);
	
	
	
	return 0;
}

return 0;
}

