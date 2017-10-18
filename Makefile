CC=gcc
CFLAGS=-I.
DEPS = mainManager.c
OBJ = mainManager.o bTree.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mainManager: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)
