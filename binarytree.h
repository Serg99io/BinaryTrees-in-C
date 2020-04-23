#include<stdbool.h>
#include "list.h"


typedef struct b_node {
  int value;
  struct b_node *left;
  struct b_node *right;
} Bin_Tree;

bool ascending(list* listval);

Bin_Tree* insert_bst(int value, Bin_Tree* bin_tree);

Bin_Tree* bst_insert_randoms(int n);

list* adding_llists(list* Linklist1,list* Linklist2);

list* bt_ints_depth_first(Bin_Tree* BT);
