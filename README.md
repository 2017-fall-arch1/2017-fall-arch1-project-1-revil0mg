# arch1-Project1-directory manager

This program contains the following files:
 bTree.h: header file of node structure & "public" interface functions
 bTree.c: implementation of binary tree
 mainManager.c: a demonstration program that uses the binary tree
 names.txt: An example file for the program.
 

To compile:
~~~
$ make
~~~

To Test after compiling:
~~~
$ ./mainManager
~~~

To delete binaries:
~~~
$ make clean
~~~

#How to use the program#

1: When the program starts, the user will be prompted to get names from a text file, which is set as names.txt, and those names will be used for this program, or the user can proceed without importing any names.

2: The user can type exit at any point in the program to quit it.

3: The user will be promped to add names to the directory, delete names from the directory, export the names of the directory to a text file (not functional), and exit the program.

4: If the user selects the option to add name by entering "1", the program will then ask for what name they would like to input. When the user finishes inputting the name the name is added to the directory.

5: If the user selects the option to delete a name by entering "2", the program will ask for the name they would like to remove from the directory. When the user finishes inputting the name, the program will look for the name in the directory and delete it.

6: If the user selects the option to save the directory to a file, the program will crash with a segmentation fault.
