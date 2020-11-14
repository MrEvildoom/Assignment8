#include <stdlib.h>
#include "integer_list.h"
#include "sort.h"


/*** Types ***/

struct il_list {
    int* data;
    int len;
    // int actual_size;
    // add current size along w/ length    
};

struct il_iterator {
    struct il_list* list;
    int* cursor;
};



/*** Private procedures ***/


/**
 * Compare data[a] and data[b], return -1 if data[a] is smaller, 1 if it is larger, and 0 if they are equal
 */

static int compare(void* datav, int a, int b) {
    // TODO 8
    return 0; // PLACEHOLDER
}


/**
 * Swap data[a] and data[b]
 */

static void swap(void* datav, int a, int b) {
    // TODO 8
}



/*** Public procedures for Integer List ***/


/**
 * Create and initialize a new list
 */

struct il_list* il_new(int size) {
    struct il_list* ls = malloc(sizeof(struct il_list));
    ls->data = malloc(sizeof(int) * size);
    ls->len = 0;
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
    list->len++;
    list->data[list->len] = value;
}


/**
 * Sort list in ascending order by value
 */

void il_sort(struct il_list* list) {
    // TODO 8
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
    return (iterator->cursor != iterator->list->data + iterator->list->len);

    // struct il_iterator* iterator = iteratorv;
    // if (ie->cursor < il.list->actual_size)
    // return 1;
    // return 0;
}


/**
 * Get pointer to next value in iteration and advance interator's cursor
 */

void* il_get_next(void* iteratorv) {
    struct il_iterator* iterator = iteratorv;
    iterator->cursor = iterator->cursor + 1;
    return iterator->cursor;

    // struct il_iterator il = iteratorv;
    // void * bob = &il->list_il->list[il->cursor];
    // il -> cursor ++
    // return bob

}


/**
 * Delete iterator
 */
void il_delete_iterator(void* iterator) {
    free(iterator);
}