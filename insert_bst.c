#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


/*this function will take an integer and a pointer of a binary tree
  and will an output pointer to the new binary tree with the integer inputted.*/ 
Bin_Tree* insert_bst(int value, Bin_Tree* bin_tree){
  /*this will check whether bin_tree is Null and then construct a node with as value the 
    inputted value and as childs NULL*/
  if (bin_tree == NULL){
    struct b_node *Bnode;
    Bnode = (struct b_node *) malloc(size(struct b_node));
    Bnode->value = value;
    Bnode->left = NULL;
    Bnode->right = NULL;
    bin_tree = Bnode;}
  //Here is checks whether the value needs to be putted left or right of the current value
  else if (bin_tree->value < value){
    bin_tree->right = insert_bst(value, bin_tree->right);}
  else if (bin_tree-> > value{
      bin_tree->left = insert_bst(value, bin_tree->right);}
  return bin_tree
