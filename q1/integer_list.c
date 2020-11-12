#include <stdlib.h>
#include "integer_list.h"
#include "sort.h"


/*** Types ***/

struct il_list {
    // TODO 4
};

struct il_iterator {
    // TODO 5
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
    // TODO 4
    return NULL;
}


/**
 * Delete list
 */

void il_delete(struct il_list* list) {
    // TODO 4
}


/**
 * Add value to end of list
 */

void il_add(struct il_list* list, int value) {
    // TODO 4
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
    // TODO 5
    return NULL; // PLACEHOLDER
}


/**
 * Return TRUE iff iterator has more values to produce
 */

int il_has_next(void* iteratorv) {
    // TODO 5
    return 0; // PLACEHOLDER
}


/**
 * Get pointer to next value in iteration and advance interator's cursor
 */

void* il_get_next(void* iteratorv) {
    // TODO 5
    return NULL; // PLACEHOLDER
}


/**
 * Delete iterator
 */
void il_delete_iterator(void* iterator) {
    // TODO 5
}