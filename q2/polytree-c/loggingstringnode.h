#ifndef __LOGGINGSTRINGNODE_H__
#define __LOGGINGSTRINGNODE_H__

// TODO
/**
 * struct definition of class and external definition of class table
 */
struct LoggingStringNode_class {
  // TODO add function pointers
  int  (*compareTo) (void*, void*);
  void (*printNode) (void*);
  void (*insert)    (void*, void*);
  void (*print)     (void*);
  void (*delete)    (void*);
};
extern struct LoggingStringNode_class LoggingStringNode_class_table;

/**
 * struct definition of object
 */
struct LoggingStringNode;
struct LoggingStringNode {
  // variables that are stored in instances of this class (including those introduced by super class)
  struct LoggingStringNode_class* class;

  // instance variables defined in super class(es)
  struct LoggingStringNode* left;
  struct LoggingStringNode* right;

  // instance variables defined in this class
  char* s;
};


/**
 * definition of new for class
 */
void* new_LoggingStringNode(char*);

/**
 * insert
 */
void LoggingStringNode_insert(void* thisv, void* nodev);

#endif /*__LOGGINGSTRINGNODE_H__*/

