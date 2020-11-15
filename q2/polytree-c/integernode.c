#include <stdlib.h>
#include <stdio.h>
#include "node.h"
#include "integernode.h"

// TODO 

struct IntegerNode_class IntegerNode_class_table = {
  IntegerNode_compareTo,
  IntegerNode_printNode,
  Node_insert,
  Node_print,
  Node_delete,
  IntegerNode_sum,
};

void IntegerNode_ctor(void* thisv, int i) {
  struct IntegerNode* this = thisv;
  Node_ctor(this);
  this->i = i;
}

int IntegerNode_compareTo(void* thisv, void* nodev) {
  struct IntegerNode* this = thisv;
  struct IntegerNode* node = nodev;
  if (this->i < node->i) {
    return -1;
  }
  if (this->i > node->i) {
    return 1;
  }
  if (this-> i = node->i) {
    return 0;
  }
}

void IntegerNode_printNode(void* thisv) {
  struct IntegerNode* this = thisv;
  printf("%d\n", this->i);
}

void* new_IntegerNode(int i) {
  struct IntegerNode* obj = malloc(sizeof(struct IntegerNode));
  obj->class = &IntegerNode_class_table;
  IntegerNode_ctor(obj, i);
  return obj;
}

int IntegerNode_sum(void* thisv) {
  struct IntegerNode* this = thisv;
  int s = this->i;
  if (this->left != NULL) {
    s = s + IntegerNode_sum(this->left);
  }
  if (this->right != NULL) {
    s = s + IntegerNode_sum(this->right);
  }
  return s;
}
