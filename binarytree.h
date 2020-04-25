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
int max(int s, int t);
int depth_help(Bin_Tree* Tree, int le);
int bt_depth(Bin_Tree* Tree);
list* help_level(Bin_Tree* Tree, int le);
list* bt_ints_breadth_first(Bin_Tree* bintree);
bool bst_contains(int n, Bin_Tree* bintr);
void step9();
void printerbst(Bin_Tree *bst);
