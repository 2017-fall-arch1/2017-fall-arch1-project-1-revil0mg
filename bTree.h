#ifndef bTree_included
#define bTree_included

/* The name variable of each node is limited to 50 characters */
typedef struct node {
  char data[50];
  struct node *left, *right;
} node;

/* Insert a node into the BTree */
node *bTreeInsert(node *temp, char *n);

/* Delete node from BTree */
node *bTreeDelete(node *temp, char *n);

/* Free the BTree from memory */
void freeTree(node *temp);

/* Print the BTree in-order */
void bTreePrint(node *temp);

#endif
