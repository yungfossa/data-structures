#ifndef __MYCODE_H__
#define __MYCODE_H__

/*My list definition*/

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
void listRemNode(node_t** l);	

/* Recursive methods */
void listPrintRec(node_t* l);
data_t listSumRec(node_t* l);


/*Screen messages method*/
void emptyListError();

#endif