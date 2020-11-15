#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "node.h"
#include "stringnode.h"
#include "loggingstringnode.h"

// TODO
struct LoggingStringNode_class LoggingStringNode_class_table = {
  // TODO initialization of class table
  StringNode_compareTo,
  StringNode_printNode,
  LoggingStringNode_insert,
  Node_print,
  Node_delete,
};

// uses the same compare and print as stringnode.

void* new_LoggingStringNode(char* s) {
  struct LoggingStringNode* obj = malloc(sizeof(struct LoggingStringNode));
  obj->class = &LoggingStringNode_class_table;
  StringNode_ctor(obj, s);
  return obj;
}

// we do not insert repeats... but you still want to print out the insert statement.

void LoggingStringNode_insert(void* thisv, void* nodev) {
  struct Node* this = thisv;
  struct Node* node = nodev;
  printf("insert ");
  Node_print(nodev);
  Node_insert(thisv, nodev);
}
