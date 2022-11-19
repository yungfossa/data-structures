/* List implementation in C */

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

struct node{
	data_t data;
	struct node* next;
};

typedef struct node node_t;

node_t* listEmpty();

node_t* listCreate(data_t x){		

	node_t* new_node = malloc(sizeof(node_t*));

	new_node->data = x;
	new_node->next = NULL;

	return new_node;
}

void listPrint(node_t* l){			

	if(l == NULL){
		printf("The list is empty!\n");
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

void listPrintRec(node_t* l){		

	if(l != NULL){
		printf("%d", l->data);
		listPrintRec(l->next);
	}
}

node_t* listAppend(node_t* l, data_t x){			

	node_t* n = l;

	if(n == NULL){
		return listCreate(x);
	}
	else{
		while(n->next != NULL){		
			n = n->next;
		}			
		
		n->next = listCreate(x);
		return l;		
	}
}

node_t* listPrepend(node_t* l, data_t x){			

	node_t* new_node = listCreate(x); 
	new_node->next = l;

	return new_node;
}

data_t listLength(node_t* l){

	int len = 0;

	while(l != NULL){
		len++;
		l = l -> next;
	}

	return len;
}

/*data_t* listToString(node_t* l){

	if(l == NULL){
		printf("The list is empty!");
		return 0;
	}

	char* s = malloc(listLength(l) + 1);
	int i = 0;

	while(l != NULL){
		s[i++] = l->data;
		l = l->next;
	}

	s[i] = '\0';

	return s;
}*/

data_t* listToArray(node_t* l){

	if(l == NULL){
		printf("The list is empty!");
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


int main(void){


	//Declaration and initialization of a new empty list
	node_t* l1 = listEmpty();
	node_t* l2 = listEmpty();

	listReqAppend(&l1);
	listReqAppend(&l2);

	/*//Sum all the the nodes
	printf("The sum of nodes: %d\n", listSum(list));*/

	//Printing the length of the list
	//printf("Length of the list: %d\n", listLength(list));

	/*//List to string
	printf("List to string: %s\n", listToString(list));*/

	/*//List to array
	printf("List to array: ");

	size_t v_size = listLength(list);
	int* v = listToArray(list);

	for(size_t i = 0; i < v_size; i++){
		printf("%d ", v[i]);
	}*/

	/*//Is the list palidrome? True = is palidrome false = is not
	printf("The list is list is palidrome? ");
	listIsPalidrome(list) ? printf("true") : printf("false");*/

	//Is l1 included in l2?	
	/*printf("The first list is included in the second list? ");
	listAndlist(l1, l2) ? printf("true") : printf("false");*/

	/*List concat*/
	node_t* concat = listEmpty();
	listConcat(l1, l2, &concat);

	//free(v);

	free(l1);
	free(l2);
	free(concat);

	return 0;
}

node_t* listEmpty(){
	return NULL;
}
