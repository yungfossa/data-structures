/* List implementation in C */

#include <stdio.h>
#include <stdlib.h>

typedef int data_t;

struct node{
	data_t data;
	struct node* next;
};

typedef struct node node_t;

/* Methods used to create a list */

node_t* listEmpty();
node_t* listCreate(data_t x);
node_t* listAppend(node_t* l, data_t x);
node_t* listPrepend(node_t* l, data_t x);
void listReqAppend(node_t** l);
void listReqPrepend(node_t** l);
void listPrint(node_t* l);


/* Other methods */

data_t listLength(node_t* l);
data_t* listToArray(node_t* l);
data_t listSum(node_t* l);
int listAndlist(node_t* l1, node_t* l2);
void listConcat(node_t* l1, node_t* l2, node_t** concat);
void listInsertNode(node_t** l, int pos);			
void listRemNode(node_t** l, int pos);	 
/*data_t* listToString(node_t* l);*/	 //working in progress

/* Recursive methods */

void listPrintRec(node_t* l);
data_t listSumRec(node_t* l);

/*Screen messages method*/
void emptyListError();

int main(void){


	//Declaration and initialization of a new empty list
	node_t* l1 = listEmpty();
	node_t* l2 = listEmpty();

	int pos;

	listReqAppend(&l1);

	int i = 0;
	int size = listLength(l1);
	while(i < size){
		printf("\nWhich node do you want to remove? ");
		scanf("%d", &pos);
		listRemNode(&l1, pos);
		listPrint(l1);
		printf("length of the list: %d", listLength(l1));
		i++;
	}
	
	free(l1);
	free(l2);

	return 0;
}

/*Implementation of methods*/

node_t* listEmpty(){
	return NULL;
}

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
		l = l->next;
	}

	return len;
}

/*data_t* listToString(node_t* l){

	if(l == NULL){
		emptyListError();
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

data_t listSumRec(node_t* l){

	if(l == NULL){
		return 0;
	}
	else{
		return l->data + listSumRec(l->next);
	}
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

void listRemNode(node_t** l, int pos){

	if(*l == NULL){
		emptyListError();
	}
	else if(pos <= 1){

		//rimuovo la testa della lista

		node_t* current_head = *l;
		(*l) = (*l)->next;
		current_head->next = NULL;
	}
	else if(pos >= listLength(*l)){

		//rimuovo l'ultimo elemento

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
}

void emptyListError(){
	printf("The list is empty!");
}
