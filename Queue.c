#include <stdio.h>
#include <stdlib.h>
//coba buat queue dulu
struct node{
	int value;
	struct node *prev;
	struct node *next;
};

struct node *head = NULL, *tail = NULL, *newNode;

void insert(int value){
	newNode = malloc(sizeof(struct node));
	newNode->prev = newNode->next = NULL;
	newNode->value = value;
	
	if(head == NULL && tail == NULL){
		head = tail = newNode;
	}else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

void dequeue(int value){
	struct node *del = head;
	head = head->next;
	head->prev = NULL;
	del->next = NULL;
	free(del);
}

void display(){
	int opt;
	struct node *curr;
	
	if(head == NULL){
		printf("Queue doesnt exist\n");
		return;
	}
	
	do{
		printf("1. Front\n2. Back\n>> ");
		scanf("%d", &opt);
		
		if(opt == 1){
			curr = head;
			while(curr != NULL){
				printf("%d ", curr->value);
				curr = curr->next;
			}
		}else if(opt == 2){
			curr = tail;
			while(curr != NULL){
				printf("%d ", curr->value);
				curr = curr->prev;
			}
		}else{
			printf("Insert right option !!!\n");
		}
	}while(opt < 1 || opt > 2);
	
	printf("\n");
}

void peek(){
	int opt;
	do{
		printf("1. Head\n2. Tail\n>> ");
		scanf("%d", &opt);
		switch(opt){
			case 1:
				printf("%d\n", head->value);
				break;
			case 2:
				printf("%d\n", tail->value);
				break;
			default:
				printf("Choose right option !!!\n");
				break;
		}
	}while(opt < 1 || opt > 2);
}

int main(){
	while(1){
		int opt;
		printf("Queue\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display queue\n");
		printf("4. Peek\n");
		printf("5. Exit\n>> ");
		scanf("%d", &opt);
			switch(opt){
				int value;
				case 1:
					printf("Insert value:\n>> ");
					scanf("%d", &value);
					insert(value);
					break;
				case 2:
					dequeue(value);
					break;
				case 3:
					display();
					break;
				case 4:
					peek();
					break;
				case 5:
					return 0;
				default:
					printf("Choose right option !!!\n");
			}
	}
return 0;
}
