#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h> /* to use strcpy*/
#include <stddef.h> /* to use NULL*/
#include <bTree.h>
/* This bTree.c was taken from my previous project a year ago and modified*/

node *bTreeInsert(struct node *temp, char *n) {
  if (temp == NULL){
    node *temp = (node *)malloc(sizeof(node));
    strcpy(temp->data, n);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
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
  node *parent = NULL;
  node *current = temp;

  while (current != NULL) {
    if (strcmp(n, current->data) < 0) {
      parent = current;
      current = current->left;
    }
    else if (strcmp(n, current->data) > 0 ) {
      parent = current;
      current = current->right;
    }
    else
      break;
  }

  if (current == NULL) {
    printf("%s is not in the directory. \n", n);
    return temp;
  }

  if (current->left == NULL) {
    if (parent == NULL) {
      temp = current->right;
      free(current);
    }
    else {
      if (strcmp(n, parent->data) < 0) {
	parent->left = current->right;
	free(current);
      }
      else {
	parent->right = current->right;
	free(current);
      }
    }
  }

  else {
    node *parentOfRightMost = current;
    node *rightMost = current->left;

    while (rightMost->right != NULL) {
      parentOfRightMost = rightMost;
      rightMost = rightMost->right;
    }

    strcpy(current->data, rightMost->data);
    if (parentOfRightMost->right == rightMost)
      parentOfRightMost->right = rightMost->left;
    else
      parentOfRightMost->left = rightMost->left;
    free(rightMost);
  }
  printf("Removing %s from the directory \n", n);
  return temp;

}

void bTreePrint(struct node *temp) {
  if (temp == NULL) {
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
  if (temp == NULL) {
    return;
  }
  if (temp->right != NULL) {
    freeTree(temp->left);
  }
  if (temp->left != NULL) {
    freeTree(temp->right);
  }
	
  free(temp);
  return;
}
