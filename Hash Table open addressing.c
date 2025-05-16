#include <stdio.h>
#include <stdlib.h>
#define M 10

int *hash[M];

int key(int value, int i){
	int key = (value % M + i) % M;
	printf("key %d value %d i %d\n", key, value, i);
	return key;
}

void hashing_insert(int value){
	int i = 0, j;
	int index = key(value, i);
	
	for(j = 0; j < M; j++){
		if(hash[index] == NULL){
			hash[index] = (int*)malloc(sizeof(int));
			*hash[index] = value;
			printf("Value %d inserted at index %d\n", value, index);
			return;
		}else{
			i++;
			index = key(value, i);
		}
	}
	printf("Table is full hashed\n");
}

void search(int value){
	int i = 0, j;
	int index = key(value, i);
	
	for(j = 0; j < M; j++){
		if(hash[index] != NULL){
			if(*hash[index] == value){
				printf("Value %d found at index %d\n", value, index);
				return;
			}
		}
		i += 1;
		index = key(value, i);
	}
	printf("Value not found in hash table !!!\n");
}

void delet(int value){
	int i = 0, j;
	int index = key(value, i);
	
	for(j = 0; j < M; j++){
		if(hash[index] != NULL){
			if(*hash[index] == value){
				printf("Value %d found at index %d and going to delete...\n", value, index);
				free(hash[index]);
				hash[index] == NULL;
				return;
			}
		}
		i += 1;
		index = key(value, i);
	}
	printf("Value not found in hash table !!!\n");
}

int main(){
	while(1){
		int opt;
		printf("Hash table basic example:\n");
		printf("1. Insert\n2. Search\n3. Delete\n4. Exit\n>> ");
		scanf("%d", &opt);
		
		switch(opt){
			int value;
			case 1:
				printf(">> ");
				scanf("%d", &value);
				hashing_insert(value);
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
				return 0;
		}
	}
	
return 0;
}
