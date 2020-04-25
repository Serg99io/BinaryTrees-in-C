
CC= gcc #compiler

main: main.c Binary_tree.c binarytree.h
	$(CC) -o main main.c Binary_tree.c
list.o: list.h list.c
	$(CC) -c list.c
