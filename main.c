#include<stdlib.h>
#include<stdbool.h>
#include <stdio.h>
#include "binarytree.h"


int main() {
  list* lis = make_random_list(3);
  print_list(lis);
  if (ascending(lis)) printf("Step1:\n this is an ascending list\n");
  else printf("this list is not ascending\n");
  Bin_Tree *b_node = malloc(sizeof(Bin_Tree));
  b_node->value = 42;
  b_node->left = NULL;
  b_node->right = NULL;
  insert_bst(3,b_node);
  insert_bst(5,b_node);
  insert_bst(1,b_node);
  insert_bst(20,b_node);
  insert_bst(30,b_node);
  insert_bst(12,b_node);
  insert_bst(13,b_node);
  printf("This is a tree T with 8 nodes made by insert bst\n");
  printerbst(b_node);
  printerbst(b_node);
  Bin_Tree* randtest = bst_insert_randoms(10);
  printf("\nThis is a random generated tree R  with 10 nodes printed in order\n");
  printerbst(randtest);
  list *lst;
  lst = bt_ints_depth_first(b_node);
  printf("\nThis is the bt_ints_depth_first list on the former made tree T\n");
  print_list(lst);
  list *lst2;
  lst2 = bt_ints_breadth_first(b_node);
  printf("This is the bt_ints_breadth_first list on the former made tree T\n");
  print_list(lst2);
  int depth = bt_depth(b_node);
  printf("This is the depth of the former created tree T: %d\n",depth);

  if (bst_contains(20,b_node)) printf("20 is in the former created tree T (checked with bst_contains)\n");

  step9();
}
