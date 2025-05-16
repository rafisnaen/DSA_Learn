#include <stdio.h>
#include <stdlib.h>

// Create Node
struct Node{
  int key;
  struct Node *left;
  struct Node *right;
};

// Create a node
struct Node *newNode(int key){
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  return (node);
}

// Insert node
struct Node *insertNode(struct Node *node, int key){
  // Find the correct position to insertNode the node and insertNode it
  if(node == NULL){
  	return (newNode(key));
  }

  if(key < node->key){
  	node->left = insertNode(node->left, key);
  }else if (key > node->key){
  	node->right = insertNode(node->right, key);
  }else{
  	 return node;
  }
  
return node;
}

struct Node *minValueNode(struct Node *node){
  struct Node *current = node;

  while(current->left != NULL)
    current = current->left;

  return current;
}

// Delete a nodes
struct Node *deleteNode(struct Node *root, int key){
  // Find the node and delete it
  if(root == NULL)
    return root;

  if(key < root->key)
    root->left = deleteNode(root->left, key);

  else if(key > root->key)
    root->right = deleteNode(root->right, key);

  else{
    if((root->left == NULL) || (root->right == NULL)){
      struct Node *temp = root->left ? root->left : root->right;

      if(temp == NULL){
        temp = root;
        root = NULL;
      }else
        *root = *temp;
      free(temp);
    }else{
      struct Node *temp = minValueNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
    }
  }

  if(root == NULL){
  	return root;
  }
  
  return root;
}

// Print the tree
void printInOrder(struct Node *root){
  if (root != NULL) {
    printInOrder(root->left);
    printf("%d ", root->key);
    printInOrder(root->right);
  }
}

void min_max(struct Node *root){
	struct Node *min = root;
		while(root->right != NULL){
			root = root->right;
		}
		printf("%d ", root->key);
	
		while(min->left != NULL){
			min = min->left;
		}
		printf("%d \n", min->key);
}

void search(struct Node *root, int val){
	if(root == NULL){
		printf("NaN\n");
		return;
	}
	
	if(val < root->key){
		search(root->left, val);
	}else if(val > root->key){
		search(root->right, val);
	}else if(val == root->key){
		printf("Exist\n");
		return;
	}
}


int main() {
  struct Node *root = NULL;

  root = insertNode(root, 2);
  root = insertNode(root, 1);
  root = insertNode(root, 7);
  root = insertNode(root, 4);
  root = insertNode(root, 5);
  root = insertNode(root, 3);
  root = insertNode(root, 8);

  printInOrder(root);

  root = deleteNode(root, 3);

  printf("\nAfter deletion: ");
  printInOrder(root);
  
  printf("\n");
  min_max(root);

  search(root, 6);
  search(root, 5);
  return 0;
}
