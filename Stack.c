#include <stdio.h>
#include <stdlib.h>

struct stack{
	int value;
	struct stack *next;
};

struct stack *push(struct stack *top, int value){
	struct stack *ptr = (struct stack*)malloc(sizeof(struct stack));
	ptr->value = value;
	
	if(top == NULL){
		top = ptr;
		top->next = NULL;
	}else{
		ptr->next = top;
		top = ptr;
	}
return top;
}

void display(struct stack *top){
	while(top != NULL){
		printf("%d ", top->value);
		top = top->next;
	}
}

struct stack *pop(struct stack *top){
	if(top == NULL){
		printf("Tidak bisa!!!\n");
		return top;
	}else{
		struct stack *del = top;
		top = top->next;
		del->next = NULL;
		free(del);
		printf("Berhasil!!!\n");
		return top;
	}
}

void peek(struct stack *top){
	printf("\n%d\n", top->value);
}

int main(){
	struct stack *top = NULL;
	top = push(top, 10);
	top = push(top, 20);
	top = push(top, 30);
	
	display(top);
	printf("\n");
	top = push(top, 40);
	display(top);
	printf("\n");
	top = pop(top);
	top = pop(top);
	display(top);
	peek(top);
}
