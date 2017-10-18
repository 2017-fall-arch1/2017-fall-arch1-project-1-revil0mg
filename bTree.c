#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h> /* to use strcpy*/
#include <stddef.h> /* to use NULL*/
#include <bTree.h>
/* This bTree.c was taken from my previous project a year ago and modified*/

struct node *root;

node *bTreeInsert(struct node *temp, char *n) {
  if (temp == NULL){
    temp = (node *)malloc(sizeof(root));
    strcpy(temp->data, n);
    temp->left = NULL;
    temp->right = NULL;
  }
  else {
    if (strcmp(n, temp->data) < 0)
      temp->left = bTreeInsert(temp->left, n);
    else if (strcmp(n, temp->data) > 0)
      temp->right = bTreeInsert(temp->right, n);
  }
  return temp;
}

node *bTreeDelete(struct node *temp, char *n) {
  if (temp == NULL)
    printf("Name not found\n");
  else if (strcmp(n, temp->data) < 0)
    temp->left = bTreeDelete(temp->left, n);
  else if (strcmp(n, temp->data) > 0)
    temp->right = bTreeDelete(temp->right, n);
  else {
    if (temp->right && temp->left) {
      printf("supposed to delete name\n"); 
    }
    else {
      if (temp->left == NULL)
	temp = temp->left;
      else if (temp->right == NULL)
	temp = temp->right;
      free(temp);
    }
    
    bTreeDelete(temp->left, n);
    bTreeDelete(temp->right, n);
  }
  return temp;
}

void bTreePrint(struct node *temp) {
  if (root == NULL) {
    printf("There are no names\n");
    return;
  }

  /* Print list in order*/
  if (temp != NULL) {
    bTreePrint(temp->left);
    printf("%s\n", temp->data);
    bTreePrint(temp->right);
  }
}

void freeTree(struct node *temp) {
  if (root == NULL) {
    return;
  }
  if (temp->right != NULL) {
    freeTree(root->left);
  }
  if (temp->left != NULL) {
    freeTree(root->right);
  }
	
  free(temp);
  return;
}
