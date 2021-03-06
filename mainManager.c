#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bTree.h"

/* Creates binary tree from file */
node *bTreeFromFile(char *filename) {
  node *BST = NULL;
  char buff[50];
  int total = 0;
  FILE *fp = fopen(filename, "r");

  if(!fp) {
    printf("File does not exist");
    fclose(fp);
    return NULL;
  }

  while(!feof(fp)) {
    fscanf(fp, "%s", buff);
    if (strcmp(buff, "") > 0) {
      BST = bTreeInsert(BST, buff);
      ++total;
    }
    strcpy(buff, "");
  }
  printf("Finished inserting %d names into the directory \n \n", total);
  fclose(fp);
  return BST;
}

/* Saves the names in order */
void saveTree(node *root, FILE *fp) {
  printf("test1");
  if (root != NULL) {
    saveTree(root->left, fp);
    fprintf(fp, "%s\n", root->data);
    printf("test2");
    saveTree(root->right, fp);
  }
  return;
}

/* Saves the names in the binary tree into file */
void saveDirectory(node *root){
  printf("test1");
  FILE *fp;
  printf("test10");
  fp = fopen("output.txt", "+ab");
  printf("test45");
  fprintf(fp, "List of names: \n");
  printf("File Opened");
  saveTree(root, fp);
  fclose(fp);
  return;
}


int main() {
  printf( "Welcome to the Personnel Management System.\n" );

  /* Create the root of the tree for the directory */
  int selection;
  char input[50];
  node *directory = NULL;
  
  while (1) {
    printf("What would you like to do?\n");
    printf("1 - Create a directory from a text file?\n");
    printf("2 - Build a new directory?\n");
    printf("exit - Quit the program\n");
    scanf("%s", input);

    /* Check input */
    if (strcmp(input, "1") == 0)
      selection = 1;
    else if (strcmp(input, "2") == 0)
      selection = 2;
    else if (strcmp(input, "exit") == 0)
      exit(1);
    else
      selection = 0;

    /* If user selects option 1 */
    if (selection == 1) {
      printf("\n Grabbing names from file... \n \n");
      directory = bTreeFromFile("names.txt");
      bTreePrint(directory);
      goto Edit_Tree;
    }

    /* If user selects option 2*/
    else if (selection == 2) {
      goto Edit_Tree;
    }
    
    /* Retry if input was invalid */
    else
      printf("INVALID INPUT!\n");
  }

  
  Edit_Tree:;
    char temp[50];

    while(1){
      printf("\nWhat would you like to do?\n");
      printf("1 - Add Name\n");
      printf("2 - Remove Name\n");
      printf("3 - Save directory to file\n");
      printf("exit - Exit program\n");

      printf("Input goes here: ");
      scanf("%s", input);

      /* Complete task based on given input */
      if (strcmp(input, "1") == 0) {
	printf("Add Name: ");
	scanf("%s", temp);
	directory = bTreeInsert(directory, temp);
	printf("\n");
	bTreePrint(directory);
	printf("\n");
      }
      else if (strcmp(input, "2") == 0) {
	printf("Remove Name: ");
	scanf("%s", temp);
	directory = bTreeDelete(directory, temp);
	printf("\n");
	bTreePrint(directory);
	printf("\n");
      }
      else if (strcmp(input, "3") == 0) {
	printf("Saving file...\n");
	saveDirectory(directory);
	printf("Saved!\n");
      }
      else if (strcmp(input, "exit") == 0) {
	printf("Thank you for using the ACME Personnel Mangement System. \n");
	freeTree(directory);
	exit(1);
      }
      else
	printf("Invalid Input\n");
    }
  
  return 0;
}
