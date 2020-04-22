#include<stdio.h>
#include<stdlib.h>
#include "binary_tree.h"

/* this procedure will take an interger n and returns a pointer to a BST which contains
   n random integers in the range [0,100)*/

Bin_tree* bst_insert_randoms(int n){
  struct b_node *Bin_tree;
  bin_t = (struct node *)malloc(sizeof(struct node));
  /* here it will loop n times till the whole tree is filled. Double occurences will not be add to the tree in insert_bst.*/
  for (i=0, i<n; i++){
    int random = rand() %100;
    bin_t = insert_bst(random,bin_t;};
  }
  return bin_t;
}
