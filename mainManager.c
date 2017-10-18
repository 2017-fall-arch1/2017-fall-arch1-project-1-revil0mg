#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bTree.h"

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
    fscanf(fp, buff);
    if (strcmp(buff, "") > 0) {
      BST = bTreeInsert(BST, buff);
      ++total;
    }
    strcpy(buff, "");
  }
  printf("Finished inserting %d names into the directory", total);
  fclose(fp);
  return BST;
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
      selection = 9;
    else
      selection = 0;

    /* If user selects option 1 */
    if (selection == 1) {
      printf("\n Grabbing names from file \n");
      directory = bTreeFromFile("names.txt");
      bTreePrint(directory);
    }

    /* If user selects option 2*/
    else if (selection == 2) {
      printf("SELECTED OPTION 2\n");
    }

    /* Quit program */
    else if (selection == 9)
      exit(1);
    /* Retry if input was invalid */
    else
      printf("INVALID INPUT!\n");
  }
  
  
  return 0;
}
