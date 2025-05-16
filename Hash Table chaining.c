#include <stdio.h>
#include <stdlib.h>
#define M 10
//kesalahan : search jika input tidak ada dalam hash table, jika sudah delete mau di search jadi infinite loop
//kesalahan : delete belum benar


struct node{
	int value;
	struct node *next;
};

struct node *hash[M];

int key(int value){
	return value % M;
}

void insert(int value){
	int index = key(value);
	
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->value = value;
	
	if(hash[index] == NULL){
		hash[index] = newNode;
	}else{
		struct node *temp = hash[index];
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void delet(int value){
    int index = key(value);
    struct node *temp = hash[index];
    struct node *prev = NULL;
    
    while(temp != NULL){
        if(temp->value == value){
            if(prev == NULL){
                hash[index] = temp->next;
            }else{
                prev->next = temp->next;
            }
            free(temp);
            printf("Value %d has been deleted\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Value does not exist in hash table\n");
}

void search(int value){
	int index = key(value);
	struct node *temp = hash[index];
	
	while(temp != NULL){
		if(temp->value == value){
			printf("Value is exist at index %d\n", index);
			return;
		}
		temp = temp->next;
	}
	printf("Value is not exist in hash table\n");
}

void display(){
	int i;
	struct node *temp;
	
	for(i = 0; i < M; i++){
		temp = hash[i];
		if(temp == NULL){
			printf("[%d]->NULL\n", i);
		}else{
			printf("[%d]->",i);
			while(temp != NULL){
				printf("%d->", temp->value);
				temp = temp->next;
			}
			printf("NULL\n");
		}
	}
}

int main(){
	
	while(1){
	int opt;
	printf("Hash table basic example:\n");
	printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n>> ");
	scanf("%d", &opt);
		switch(opt){
			int value;
			case 1:
				printf(">> ");
				scanf("%d", &value);
				insert(value);
				break;
			case 2:
				printf(">> ");
				scanf("%d", &value);
				search(value);
				break;
			case 3:
				printf(">> ");
				scanf("%d", &value);
				delet(value);
				break;
			case 4:
				display();
				break;
			case 5:
				return 0;
			default:
				printf("Choose right option !!!\n");
		}
	}
	
return 0;
}
