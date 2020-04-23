
CC= gcc #compiler

main: main.c ascend.c binarytree.h bst_insert_randoms.c bt_ints_depth_first.c insert_bst.c
	$(CC) -o main main.c ascend.c binarytree.h bst_insert_randoms.c bt_ints_depth_first.c insert_bst.c


list.o: list.h list.c
	$(CC) -c list.c
