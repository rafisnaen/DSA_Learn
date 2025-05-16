#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//coba buat queue dulu
struct node{
	int value;
	char kategori[100];
	struct node *prev;
	struct node *next;
};

struct node *head = NULL, *tail = NULL, *newNode;

void insert(int value){
	char kategori[100];
	printf("Insert category : (rendah, sedang, tinggi)\n>> ");
	scanf(" %s", kategori);
	newNode = malloc(sizeof(struct node));
	newNode->prev = newNode->next = NULL;
	newNode->value = value;
	strcpy(newNode->kategori, kategori);
	
	if(head == NULL && tail == NULL){
		head = tail = newNode;
	}else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

int getPriority(const char *kategori){
    if(strcmp(kategori, "rendah")== 0){
        return 0;
    }else if(strcmp(kategori, "sedang")== 0){
        return 1;
    }else if(strcmp(kategori, "tinggi")== 0){
        return 2;
    }
}

void sort(){
    struct node *temp, *nextNode;
    int swapped;

    if(head == NULL || head->next == NULL){
    	printf("1 node only in queue / queue doesnt exist");
        return;
    }

    do{
        swapped = 0;
        temp = head;

        while(temp->next != NULL){
            nextNode = temp->next;

            int prioritytemp = getPriority(temp->kategori);
            int priorityNext = getPriority(nextNode->kategori);

            if(prioritytemp < priorityNext){
                int tempValue = temp->value;
                char tempKategori[100];
                strcpy(tempKategori, temp->kategori);

                temp->value = nextNode->value;
                strcpy(temp->kategori, nextNode->kategori);

                nextNode->value = tempValue;
                strcpy(nextNode->kategori, tempKategori);

                swapped = 1;
            }

            temp = nextNode;
        }
    }while(swapped == 1);
}

void dequeue(int value){
	sort();
	struct node *del = head;
	head = head->next;
	head->prev = NULL;
	del->next = NULL;
	free(del);
}

void display(){
	sort();
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
		printf("Priority Queue\n");
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
