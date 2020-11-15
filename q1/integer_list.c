#include <stdlib.h>
#include "integer_list.h"
#include "sort.h"
#include <stdio.h>


/*** Types ***/

struct il_list {
    int* data;
    int len;  // number of elements in list
    int size; // max elements in list
};

struct il_iterator {
    struct il_list* list;
    int* cursor;
};



/*** Private procedures ***/


/**
 * Compare data[a] and data[b], return -1 if data[a] is smaller, 1 if it is larger, and 0 if they are equal
 */

static int compare(void* listv, int a, int b) {
    struct il_list* list = listv;
    if (list->data[a] < list->data[b]) {
        return -1;
    }
    if (list->data[a] > list->data[b]) {
        return 1;
    }
    if (list->data[a] == list->data[b]) {
        return 0;
    }
}


/**
 * Swap data[a] and data[b]
 */

static void swap(void* listv, int a, int b) {
  struct il_list* list = listv;
  int t = list->data[a];
  list->data[a] = list->data[b];
  list->data[b] = t;
}



/*** Public procedures for Integer List ***/


/**
 * Create and initialize a new list
 */

struct il_list* il_new(int size) {
    struct il_list* ls = malloc(sizeof(struct il_list));
    ls->data = malloc(sizeof(int) * size);
    ls->len = 0;
    ls->size = size;
    return ls;
}


/**
 * Delete list
 */

void il_delete(struct il_list* list) {
    // TODO 4
    free(list->data);
    free(list);
}


/**
 * Add value to end of list
 */

void il_add(struct il_list* list, int value) {
  if (list->len < list->size) {
    list->data[list->len] = value;
    list->len++;
  } else {
    printf("il_add failed, container too small");
  }
}


/**
 * Sort list in ascending order by value
 */

void il_sort(struct il_list* list) {
  sort(list, list->len, compare, swap);
}



/*** Public procedures for Integer List Iterator ***/


/**
 * Create and initialize iterator for list
 */

void* il_iterator(void* listv) {
    struct il_list* list = listv;
    struct il_iterator* iterator = malloc(sizeof(*iterator));
    iterator->list = list;
    iterator->cursor = list->data;
    return iterator;
}


/**
 * Return TRUE iff iterator has more values to produce
 */

int il_has_next(void* iteratorv) {
    struct il_iterator* iterator = iteratorv;
    return (iterator->cursor < iterator->list->data + iterator->list->len);
}


/**
 * Get pointer to next value in iteration and advance interator's cursor
 */

void* il_get_next(void* iteratorv) {
    struct il_iterator* iterator = iteratorv;
    void* temp = iterator->cursor;
    iterator->cursor ++;
    return temp;
    // iterator->cursor = iterator->cursor + 1;
    // return iterator->cursor;
}


/**
 * Delete iterator
 */
void il_delete_iterator(void* iterator) {
    free(iterator);
}


// void test_il() {
//   struct il_list* intlist = il_new(4);
//   printf("\n test constructor");
//   printf("\n intlist max size: %d", intlist->size);
//   printf("\n intlist current size: %d", intlist->len);

//   il_add(intlist, 4);
//   il_add(intlist, 6);
//   il_add(intlist, 2);
//   il_add(intlist, 1);
//   printf("\n test add");
//   printf("\n intlist max size: %d", intlist->size);
//   printf("\n intlist current size: %d", intlist->len);
//   printf("\n intlist data 1: %d", intlist->data[0]);
//   printf("\n intlist data 1: %d", intlist->data[1]);
//   printf("\n intlist data 1: %d", intlist->data[2]);
//   printf("\n intlist data 1: %d", intlist->data[3]);

//   il_add(intlist, 1);
//   // add is working.
//   printf("\n intlist max size: %d", intlist->size);
//   printf("\n intlist current size: %d", intlist->len);
//   printf("\n intlist data 1: %d", intlist->data[0]);
//   printf("\n intlist data 1: %d", intlist->data[1]);
//   printf("\n intlist data 1: %d", intlist->data[2]);
//   printf("\n intlist data 1: %d", intlist->data[3]);
//   // locations outside of the array just have 0.
//   printf("\n intlist data 1: %d", intlist->data[4]);

//   il_sort(intlist);
//   printf("\n test sort");
//   // sort if working. this probably means swap and compare are too.
//   printf("\n intlist max size: %d", intlist->size);
//   printf("\n intlist current size: %d", intlist->len);
//   printf("\n intlist data 1: %d", intlist->data[0]);
//   printf("\n intlist data 1: %d", intlist->data[1]);
//   printf("\n intlist data 1: %d", intlist->data[2]);
//   printf("\n intlist data 1: %d", intlist->data[3]);
//   printf("\n intlist data 1: %d", intlist->data[4]);
//   printf("\n intlist data 1: %d", intlist->data[5]);

//   // mustb e something wrong with iterator/hasnext or getnext?
// }