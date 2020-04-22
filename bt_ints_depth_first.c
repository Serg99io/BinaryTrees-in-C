#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"


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

list* bt_ints_depth_first(Bin_tree* BT){
  list* finlist = (list*) malloc(sizeof(list));
  if (BT == NULL)
    return NULL;
  /*this will add for each node left subtree prceding with the value of the node preceding
  with the integer in the right subtree*/
  else {
    finlist->first = BT->value;
    finlist->rest = bt_ints_depth_first(BT-left);
    return adding_llists(finlist, bt_ints_depth_first(BT->right));
  }
}
