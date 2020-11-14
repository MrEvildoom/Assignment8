#include <stdio.h>
#include <string.h>
#include "sort.h"


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

int comparestr(void* listv, int a, int b) {
    char** list = listv;
    return strcmp (list[a], list[b]);
    // if Return value < 0 then it indicates str1 is less than str2.
    // if Return value > 0 then it indicates str2 is less than str1.
    // if Return value = 0 then it indicates str1 is equal to str2
}

void swapstr(void* listv, int a, int b) {
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
        for (int j = i + 1; j < length; j++) {
            // int temp = cmp(list, i, j);
            // char char1 = list[i];
            // char char2 = list[j];
            // printf("\n char 1: %c, char 2: %c compval: %d", char1, char2, temp);
            if (cmp(list, i, j) > 0) 
                swp(list, i, j);
        }
}

void test_sort() {
  // char* listchar[] = {"a", "b", "c"};
  //   char* listchar[] = {"Cat", "Elephant", "Dog", "Lion", "Zebra",q "Ape"};
  //   sort (listchar, 6, comparechar, swapchar);
  //   for (int i = 0; i < 6; i++)
  //       printf("%s\n", listchar[i]);

  //   int listint[] = {1,4,5,2,6,3};
  //   sort (&listint, 6, compareint, swapint);
  //   for (int i = 0; i < 6; i++)
  //       printf("%d\n", listint[i]);
}

void test_compare() {
  char* listchar[] = {"a", "b"};
  // int* listin[] = {1,2};
  printf("\n%d", comparestr(listchar, 0, 1));
  // printf("\n%d", compareint(listin, 0, 1));
}

// int compare(char** list, int a, int b) {
//     return strcmp (list[a], list[b]);
// }

// void swap(char** list, int a, int b) {
//     char* t = list[a];
//     list[a] = list[b];
//     list[b] = t;
// }

// // TODO 7: Change this procedure sort generic arrays (i.e., arrays of any type) 
// //         by replacing char** with void* and adding function pointer parameters.
// //         Update test_sort to use the new sort to sort 
// //             (a) this arrays of strings; AND
// //             (b) an array of integers (this will help you with TODO 9)
// //         See also TODO 8 in sort.h
// void sort(char** list, int length) {
//     for (int i = 0; i < length; i++)
//         for (int j = i + 1; j < length; j++)
//             if (compare(list, i, j) > 0) 
//                 swap(list, i, j);
// }

// void test_sort() {
//     char* list[] = {"Cat", "Elephant", "Dog", "Lion", "Zebra", "Ape"};
//     sort (list, 6);
//     for (int i = 0; i < 6; i++)
//         printf("%s\n", list[i]);
// } 