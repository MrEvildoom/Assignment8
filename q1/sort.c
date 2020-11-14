#include <stdio.h>
#include <string.h>
#include "sort.h"


int comparechar(void* listv, int a, int b) {
    char* list = listv;
    return strcmp (list + a, list + b);
    // if Return value < 0 then it indicates str1 is less than str2.
    // if Return value > 0 then it indicates str2 is less than str1.
    // if Return value = 0 then it indicates str1 is equal to str2
}

int compareint(void* listv, int a, int b) {
  int* list = listv;
  if (list + a < list + b) {
    return -1;
  }
  if (list + a > list + b) {
    return 1;
  }
  if (list + a == list + b) {
    return 0;
  }
}

void swapint(void* listv, int a, int b) {
    int** list = listv;
    int* t = list[a];
    list[a] = list[b];
    list[b] = t;
}


void swapchar(void* listv, int a, int b) {
    char** list = listv;
    char* t = list[a];
    list[a] = list[b];
    list[b] = t;
}


// TODO 7: Change this procedure sort generic arrays (i.e., arrays of any type) 
//         by replacing char** with void* and adding function pointer parameters.
//         Update test_sort to use the new sort to sort 
//             (a) this arrays of strings; AND
//             (b) an array of integers (this will help you with TODO 9)
//         See also TODO 8 in sort.h

// NOTES!!!!:
// 4 parameters
// char** -> void*
// for other two: swap and compare methods
// the only diff between sorting for a char and int...
// do not need to put those into sort.h

void sort (
    void* list,
    int length,
    int (*cmp) (void*, int a, int b),
    void (*swp) (void* list, int a, int b)
) {
    for (int i = 0; i < length; i++)
        for (int j = i + 1; j < length; j++)
            if (cmp(list, i, j) > 0) 
                swp(list, i, j);
}

void test_sort() {
    char* list[] = {"Cat", "Elephant", "Dog", "Lion", "Zebra", "Ape"};
    sort (list, 6, comparechar, swapchar);
    for (int i = 0; i < 6; i++)
        printf("%s\n", list[i]);
}

void test_sort_int() {
    int list[] = {1,4,5,2,6,3};
    sort (&list, 6, compareint, swapint);
    for (int i = 0; i < 6; i++)
        printf("%d\n", list[i]);
}