#include <stdio.h>
#include <stdlib.h>

struct node{
	int value;
	struct node *next;
};

struct frequent{
	int value;
	int frequency;
	struct frequent *next;
};

struct node *head = NULL, *tail = NULL, *curr = NULL;

void insertNode(int value, int opt){
	struct node *newNode = (struct node*)malloc(sizeof(struct node));
	newNode->next = NULL;
	newNode->value = value;
	
	if(head == NULL){
		printf("New linked list inserted..\n");
		head = tail = curr = newNode;
	}else{
		if(opt == 1){
			newNode->next = head;
			head = newNode;
		}else if(opt == 2){
			tail->next = newNode;
			tail = newNode;
		}else if(opt == 3){
			
			curr = head;
			int search_value;
			scanf("%d", &search_value);
			
			while(curr != NULL){
				if(curr->value == search_value){
					if(curr == tail){
						printf("Going to insert new data after %d(tail)\n", curr->value);
						tail->next = newNode;
						tail = newNode;
					}else{
						printf("Going to insert new data after %d\n", curr->value);
						newNode->next = curr->next;
						curr->next = newNode;
						printf("Insert completed.\n");
					}
					break;
				}
				curr = curr->next;
			}
			if(curr == NULL){
				printf("Data doesn't exist.\n");
			}
		}
	}
}

void display(){
	curr = head;
	while(curr != NULL){
		printf("%d ", curr->value);
		curr = curr->next;
	}
}

void deleteNode(int value){
	int flag = 0;
	struct node *deleteNode = head;
	while(deleteNode != NULL){
		
		if(deleteNode->value == value){
			printf("Going to delete %d.\n", deleteNode->value);
			flag = 1;
			
			if(head == tail){
				
				printf("Delete the only data on linked list.\n");
				free(deleteNode);
				curr = head = tail = NULL;
				return;
				
			}else if(deleteNode == head){
				
				head = head->next;
				free(deleteNode);
				printf("Case 1\n");
				return;
				
			}else if(deleteNode == tail){
				
				curr = head;
				while(curr->next != tail){
					curr = curr->next;
				}
				tail = curr;
				curr->next = NULL;
				free(deleteNode);
				printf("Case 2\n");
				return;
				
			}else{
				curr = head;
				while(curr->next != deleteNode){
					curr = curr->next;
				}
				curr->next = deleteNode->next;
				deleteNode->next = NULL;
				printf("Case 3\n");
				free(deleteNode);
				return;
			}
		}
		
		deleteNode = deleteNode->next;
	}
	if(flag == 0){
		printf("Data doesn't exist on linked list.\n");
	}
}


void search(int value){
	int iteration = 1;
	curr = head;
	while(curr != NULL){
		if(value == curr->value){
			printf("Data %d exist in list %d\n", curr->value, iteration);
		}
		iteration += 1;
		curr = curr->next;
	}
}

void sort(){
	int swapped;
	struct node* nextNode = NULL;
	
	do{
		curr = head;
		swapped = 0;
		while(curr->next != NULL){
			nextNode = curr->next;
			if(curr->value > nextNode->value){
				int temp = nextNode->value;
				nextNode->value = curr->value;
				curr->value = temp;
				swapped = 1;
			}
			curr = curr->next;	
		}
	}while(swapped == 1);
}

void freq(){
    curr = head;
    struct frequent *curr_f = NULL, *head_f = NULL, *tail_f = NULL;
    
    while(curr != NULL){
        if(head_f == NULL && tail_f == NULL){
            struct frequent *newNode = malloc(sizeof(struct frequent));
            newNode->frequency = 1;
            newNode->next = NULL;
            head_f = tail_f = newNode;
            newNode->value = curr->value;
        }else{
            curr_f = head_f;
            while(curr_f != NULL){
                if(curr_f->value == curr->value){
                    curr_f->frequency += 1;
                    break;
                }
                curr_f = curr_f->next;
            }

            if(curr_f == NULL){
                struct frequent *newNode = malloc(sizeof(struct frequent));
                newNode->frequency = 1;
                newNode->next = NULL;
                newNode->value = curr->value;
                tail_f->next = newNode;
                tail_f = newNode;
            }
        }
        
        curr = curr->next;
    }
    
    int max_value = 0;
    int max_frequency = 0;
    curr_f = head_f;
    while(curr_f != NULL){
        if(curr_f->frequency > max_frequency){
            max_value = curr_f->value;
            max_frequency = curr_f->frequency;
        }
        curr_f = curr_f->next;
    }
    
    curr_f = head_f;
    while(curr_f != NULL){
        struct frequent *del = curr_f;
        curr_f = curr_f->next;
        free(del);
    }

    printf("Most appeared in list : %d, with frequency = %d\n", max_value, max_frequency);
}

int lobby(){
	int opt;
	printf("Single linked list\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Search\n");
	printf("4. Display all data\n");
	printf("5. Sort data\n");
	printf("6. Most appeared value\n");
	printf("7. fdhsafdsafea\n");
	printf(">> ");
	scanf("%d", &opt);
	
return opt;
}

void min_max(){
	int max = 0;
	int min = 999;
	curr = head;
	while(curr != NULL){
		if(curr->value > max){
			max = curr->value;
		}
		if(curr->value < min){
			min = curr->value;
		}
		curr = curr->next;
	}
	printf("Min : %d, Max : %d\n", min, max);
}

int main(){
	
	while(1){
		int opt = lobby();
		switch(opt){
			int value, choice;
			case 1:
				scanf("%d", &value);
				printf("1. Head\n2. Tail\n3. Position\n>> ");
				scanf("%d", &choice);
				insertNode(value, choice);
				printf("\n");
				break;
			case 4:
				display();
				printf("\n");
				break;
			case 2:
				scanf("%d", &value);
				deleteNode(value);
				printf("\n");
				break;
			case 3:
				scanf("%d", &value);
				search(value);
				printf("\n");
				break;
			case 5:
				sort();
				display();
				printf("\n");
				break;
			case 6:
				freq();
				printf("\n");
				break;
			case 7:
				min_max();
				break;
			default:
				printf("Choose the right option !!!\n");
				break;
		}	
	}
	
	
return 0;
}
