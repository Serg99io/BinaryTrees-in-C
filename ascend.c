//All the necessary libraries and the binary_tree.h file that are used in this function
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include "binarytree.h"

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

