#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binarytree.h"

//Here are the functions for the lists.
list* make_random_list(int length) {
  list* list;
  struct cell *c;
  list = NULL;
  while (length--) {
    c = (struct cell *) malloc(sizeof(struct cell));
    c->first = rand() % 100;
    c->rest = list;
    list = c;
  }
  return list;
}

int list_length(list *list) {
  int length = 0;

  while (list) {
    length++;
    list = list->rest;
  }

  return length;
}

void print_list(list *list) {
  while (list) {
    printf("%d ", list->first);
    list = list->rest;
  }
  printf("\n");
}

// Free the memory of all of the cells in list
void free_list(list *list) {
  struct cell *next;

  while (list) {
    next = list->rest;
    free(list);
    list = next;
  }
}

/*This function will take a pointer to a linked list of integers and returns a boolean which is true if the elements of the list are (strictly) in ascending order and false otherwise*/
bool ascending(list* listval){
  // check whether the list has finished and still in ascending order
  if (listval == NULL || listval->rest == NULL)
    return true;
  // check for strictly ascending order and sends rest of list back to function
  else if (listval->first < listval->rest->first)
    return ascending(listval->rest);
  // if the list is not in ascending order it will return false
  else
    return false;
}


/*this function will take an integer and a pointer of a binary tree
  and will an output pointer to the new binary tree with the integer inputted.*/ 
Bin_Tree* insert_bst(int value, Bin_Tree *bin_tree){
  /*this will check whether bin_tree is Null and then construct a node with as value the 
    inputted value and as childs NULL*/
  if (bin_tree == NULL){
    struct b_node *Bnode;
    Bnode = (struct b_node *) malloc(sizeof(struct b_node));
    Bnode->value = value;
    Bnode->left = NULL;
    Bnode->right = NULL;
    bin_tree = Bnode;}
  //Here is checks whether the value needs to be putted left or right of the current value
  else if (bin_tree->value > value){
    bin_tree->left = insert_bst(value, bin_tree->left);}
  else if (bin_tree->value < value){
      bin_tree->right = insert_bst(value, bin_tree->right);}
  return bin_tree;
}
Bin_Tree* bst_insert_randoms(int n){
  Bin_Tree *Bst;
  Bst = NULL;
  /* here it will loop n times till the whole tree is filled. Double occurences will not be add to the tree in insert_bst.*/
  int random;
  while(n--){
    random = rand() %100;
    Bst = insert_bst(random,Bst);
  }
  return Bst;
}

/* a helper function that will add two linked lists together*/

list* adding_llists(list* Linklist1,list* Linklist2){ 
  list* final_list = Linklist1;
  //check whether lists are empthy
  if (Linklist1 == NULL)
    return Linklist2;
  else if (Linklist2 == NULL)
    return Linklist1;
  //going to end of first list and appending Linklist2
  while(final_list->rest!=NULL){
    final_list = final_list->rest;}
  final_list->rest = Linklist2;
  return final_list;
}
    
	     
/* a procedure which takes a pointer to a binary tree and returns a pointer to a 
linked list of the integers contained in the BT in the following order:
for each node the list should contain the integer contained in the left subtree
preceding the integer at the node preceding the integer contained in the right subtree.*/

list* bt_ints_depth_first(Bin_Tree* BT){
  list* finlist = (list*) malloc(sizeof(list));
  if (BT == NULL)
    return NULL;
  /*this will add for each node left subtree prceding with the value of the node preceding
  with the integer in the right subtree*/
  else {
    finlist->first = BT->value;
    finlist->rest = bt_ints_depth_first(BT->left);
    return adding_llists(finlist, bt_ints_depth_first(BT->right));
  }
}
//helperfunction that will find the maximum between two integers
int max(int s, int t){
  if (s > t)
    return s;
  else
    return t;

}

/* helperfunction that will use recursion and the max function and will return the depth of an integer*/
int depth_help(Bin_Tree* Tree, int le){
  if (Tree == NULL)
    return le;
  else
    return max(depth_help(Tree->left, le +1), depth_help(Tree->right,le+1));
}

/*function bt_depth that will find the the lenth of the long*/

//this will help to find the level of an integer
list* help_level(Bin_Tree* Tree , int le){
  list* finlist = (list*) malloc(sizeof(list));
  if (Tree==NULL)
    return NULL;
  else if (le==0){
    finlist->first=Tree->value;
    return finlist;
  }
  else{
    return adding_llists(help_level(Tree->left,le-1), help_level(Tree->right,le-1));
  }
}
			
/*  a C procedure bt_ints_breadth_first which takes a pointer to a BT and returns a pointer to a linked list of the integers contained in the BT in the following order: each node the list should be preceded by all nodes shallower in the tree and succeeded by all nodes deeper in the tree. */ 
list* bt_ints_breadth_first(Bin_Tree* bintree) {
  int i, row;
  list* finlist = (list*) malloc(sizeof(list));
  row = help_level(bintree,0);
  for (i=0;i<row;i++)
    finlist=adding_llists(finlist,help_level(bintree,i));
  return finlist;
}

//This function will check whether bst contains a certain integer.
bool bst_contains(int n, Bin_Tree* bintr) {
  if (bintr == NULL) 
    return false;
  
  else if (n == bintr->value)
    return true;
  else if (n < bintr->value){
    return bst_contains(n, bintr->right);
  }
  else if (n > bintr->value){
    return bst_contains(n, bintr->left);
    }
}





// this function prints the bst in order.
void printerbst(Bin_Tree *bst){
  if (bst != NULL){
    printerbst(bst->left);
    printf("%d ", bst->value);
    printerbst(bst->right);
  }
}

int main() {
  list* lis = make_random_list(3);
  print_list(lis);
  if (ascending(lis)) printf("this is an ascending list\n");
  else printf("this list is not ascending\n");

  Bin_Tree *b_node = malloc(sizeof(Bin_Tree));
  b_node->value = 42;
  b_node->left = NULL;
  b_node->right = NULL;
  insert_bst(3,b_node);
  insert_bst(5,b_node);
  printerbst(b_node);
  printf("This is a tree with 3 nodes printed in order\n");
  Bin_Tree* randtest = bst_insert_randoms(10);
  printerbst(randtest);
  printf("This is a random generated tree with 10 nodes printed in order\n");

}
   
