/*-----------------------------------------------------------------------------
 *				HTBLA-Leonding / Class: <your class name here>
 *-----------------------------------------------------------------------------
 * Exercise Number: #exercise_number#
 * File:			bst.cpp
 * Author(s):		Peter Bauer
 * Due Date:		May 31, 2017
 *-----------------------------------------------------------------------------
 * Description:
 * <your description here>
 *-----------------------------------------------------------------------------
*/
#include "bst.h"
#include <stdlib.h>
#include "general.h"

struct Node{
  int value;
  struct Node* left;
  struct Node* right;
};

Bst new_bst(){
  Bst newBst=(Bst)malloc(sizeof(struct Node));
  newBst->left=0;
  newBst->right=0;
  newBst->value=0;
  newBst=0;
  return newBst;
}

void delete_bst(Bst bst){
  if(bst!=0)
  {
    delete_bst(bst->left);
    delete_bst(bst->right);
    sfree(bst);
  }
}

int get_depth(Bst bst){
  if(bst==0)
  {
    return 0;
  }
  else
  {
    int ldepth=get_depth(bst->left);
    int rdepth=get_depth(bst->right);

    if(ldepth>rdepth)
    {
      return ldepth+1;
    }
    else
    {
      return rdepth+1;
    }
  }
}

void add(Bst* bst, int value){
  if((*bst)==0)
  {
    Bst currBst=(Bst)malloc(sizeof(struct Node));
    currBst->left=0;
    currBst->right=0;
    currBst->value=value;
    *bst=currBst;
  }
  else if(value<=(*bst)->value)
  {
    add(&(*bst)->left,value);
  }
  else
  {
    add(&(*bst)->right,value);
  }

}

int root_value(Bst bst){
  return bst->value;
}

Bst left_subtree(Bst root){
  return root->left;
}

Bst right_subtree(Bst root){
  return root->right;
}

int traverse_pre_order(Bst bst, int *elements, int start){
  return 0;
}

int traverse_in_order(Bst bst, int *elements, int start){
  return 0;
}

int traverse_post_order(Bst bst, int *elements, int start){
  return 0;
}

bool are_equal(Bst bst1, Bst bst2){
  if((get_depth(bst1)==get_depth(bst2)))
  {
    if(bst1==bst2)
    {
      return true;
    }
  }

  return false;
}

void most_left_longest_branch(Bst bst, Bst* branch){
  if(bst == 0)
  {
    return;
  }
  add(branch, bst->value);
  get_depth(bst->left) >= get_depth(bst->right) ? most_left_longest_branch(bst->left, branch):most_left_longest_branch(bst->right, branch);
}

int get_number_of_subtrees(Bst bst){
  if(bst == 0)
  {
    return -1;
  } 
  return get_number_of_subtrees(bst->left) +1+ get_number_of_subtrees(bst->right)+1;
}
