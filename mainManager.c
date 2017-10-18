#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bTree.h"

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
      selection = 0;
    else if (strcmp(input, "2") == 0)
      selection = 1;
    else if (strcmp(input, "exit") == 0)
      selection = 9;

    /* If user selects option 1 */
    if (selection == 1) {
      printf("SELECTED OPTION 1\n");
    }

    /* If user selects option 2 IF STATEMENT*/
    else if (selection == 2) {
      printf("SELECTED OPTION 2\n");
    }

    
    else if (selection == 9)
      exit(1);
    else
      printf("INVALID INPUT!\n");
  }
  
  
  return 0;
}
