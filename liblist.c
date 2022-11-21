#include "mylist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* Methods to create a list */

node_t* listEmpty(){
	return NULL;
}

node_t* listCreate(data_t x){		

	node_t* new_node = malloc(sizeof(node_t*));

	new_node->data = x;
	new_node->next = NULL;

	return new_node;
}

node_t* listAppend(node_t* l, data_t x){			

	node_t* new_node = l;

	if(new_node == NULL){
		return listCreate(x);
	}
	else{
		while(new_node->next != NULL){		
			new_node = new_node->next;
		}			
		
		new_node->next = listCreate(x);
		return l;		
	}
}

node_t* listPrepend(node_t* l, data_t x){			

	node_t* new_node = listCreate(x); 
	new_node->next = l;

	return new_node;
}

void listReqAppend(node_t** l){

	int n, x;

	printf("Number of nodes to link: ");
	scanf("%d", &n);
	printf("\n");

	printf("Value to memorize inside the node:\n");
	//Adding new nodes starting from an empty list and using "listAppend" method
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		*l = listAppend(*l, x);
	}

	printf("\nCurrent list: ");
	listPrint(*l);
	printf("\n\n");

	return;
}

void listReqPrepend(node_t** l){

	int n, x;

	printf("Number of nodes to link: ");
	scanf("%d", &n);
	printf("\n");

	printf("Value to memorize inside the node:\n");
	//Adding new nodes starting from an empty list and using "listAppend" method
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		*l = listPrepend(*l, x);
	}

	printf("\nCurrent list: ");
	listPrint(*l);
	printf("\n\n");

	return;
}

void listPrint(node_t* l){			

	if(l == NULL){
		emptyListError();
	}
	else{
		printf("[ ");

		while(l != NULL){
			printf("%d ", l->data);
			l = l->next;
		}

		printf("]");
	}	
}


/* Other methods */

data_t listLength(node_t* l){

	int len = 0;

	while(l != NULL){
		len++;
		l = l->next;
	}

	return len;
}

data_t* listToArray(node_t* l){

	if(l == NULL){
		emptyListError();
		return 0;
	}

	int* v = malloc(sizeof(int)*listLength(l));
	int i = 0;

	while(l != NULL){
		v[i++] = l->data;
		l = l->next;
	}
	
	return v;
}

data_t listSum(node_t* l){

	int sum = 0;

	while(l != NULL){
		sum += l->data;
		l = l->next;
	}

	return sum;	
}

int listAndlist(node_t* l1, node_t* l2){

	if(listLength(l2) < listLength(l1) || l1 == NULL || l2 == NULL){
		return 0;
	}	

	int x, count = 0;
	node_t* headl2 = l2;

	while(l1 != NULL){

		while(l2 != NULL){
			x = l2->data;

			if(l1->data == x)
				count++;

			l2 = l2->next;
		}

		l2 = headl2;
		l1 = l1->next;
	}

	if(count >= listLength(l1)){
		return 1;
	}
	else{
		return 0;
	}
}

void listConcat(node_t* l1, node_t* l2, node_t** concat){

	if(l1 == NULL){
		*concat = l2;
	}
	else if(l2 == NULL){
		*concat = l1;
	}
	else{

	//if l1 && l2 are not empty
		while(l1 != NULL){
			data_t x = l1->data;
			*concat = listAppend(*concat, x);
			l1 = l1->next;
		}
		
		while(l2 != NULL){
			data_t x = l2->data;
			*concat = listAppend(*concat, x);
			l2 = l2->next;
		}
	}

	printf("List concatenate l1 + l2: ");
	listPrint(*concat);
	printf("\n");

}

void listInsertNode(node_t** l, int pos){

	data_t x;
	node_t* head = *l;

	if(*l == NULL){
		emptyListError();
		return;
	}
	else if(listLength(*l) - 1 < pos){
		printf("The position is greater than the length of the list, the node will be added at the end of the list\n");
		printf("Insert the value to memorize in the node: ");
		scanf("%d", &x);
		*l = listAppend(*l, x);
	}
	else if(pos <= 0){
		printf("The position is lesser than the length of the list, the node will be added at the start of the list\n");
		printf("Insert the value to memorize in the node: ");
		scanf("%d", &x);
		*l = listPrepend(*l, x);

		head = *l;
	}
	else{
		for(int i = 0; i < pos - 1; i++){
			*l = (*l)->next;
		}

		printf("Insert the value to memorize in the node: ");
		scanf("%d", &x);

		node_t* aux = listCreate(x);

		aux->next = (*l)->next;
		(*l)->next = aux;
	}

	printf("\nThe node has been added successfully: ");
	listPrint(head);
}

void listRemNode(node_t** l){

	int pos;

	printf("Which node do you want to remove? ");
	scanf("%d", &pos);

	if(*l == NULL){
		emptyListError();
	}
	else if(pos <= 1){

		//removing the head of the list

		node_t* current_head = *l;
		(*l) = (*l)->next;
		current_head->next = NULL;
	}
	else if(pos >= listLength(*l)){

		//removing the last node of the list

		node_t* aux = *l;

		for(int i = 0; i < listLength(*l) - 2; i++){
		 	aux = aux->next;
		}

		aux->next = NULL;
	}
	else{

		node_t* aux = *l;

		for(int i = 0; i < pos - 2; i++){
			aux = aux->next;
		}

		aux->next = aux->next->next;
	}

	printf("The node has been removed successfully: ");
	listPrint(*l);
}

/* Recursive method */

void listPrintRec(node_t* l){		

	if(l != NULL){
		printf("%d", l->data);
		listPrintRec(l->next);
	}
}

data_t listSumRec(node_t* l){

	if(l == NULL){
		return 0;
	}
	else{
		return l->data + listSumRec(l->next);
	}
}

/* Screen messages method */

void emptyListError(){
	printf("The list is empty!");
}