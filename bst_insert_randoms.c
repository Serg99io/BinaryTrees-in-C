#include<stdio.h>
#include<stdlib.h>
#include "binarytree.h"

/* this procedure will take an interger n and returns a pointer to a BST which contains
   n random integers in the range [0,100)*/

Bin_Tree* bst_insert_randoms(int n){
  struct b_node *Bin_tree;
  Bin_Tree* Bin_Tree = (struct b_node *) malloc(sizeof(struct b_node));

  /* here it will loop n times till the whole tree is filled. Double occurences will not be add to the tree in insert_bst.*/
  int i;
  for (i=0, i<n; i++;){
    int random = rand() %100;
    Bin_Tree = insert_bst(random,Bin_Tree);
  }
  return Bin_Tree;
}
