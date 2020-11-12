#include <stdio.h>
#include <string.h>
#include "sort.h"


int compare(char** list, int a, int b) {
    return strcmp (list[a], list[b]);
}

void swap(char** list, int a, int b) {
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
void sort(char** list, int length) {
    for (int i = 0; i < length; i++)
        for (int j = i + 1; j < length; j++)
            if (compare(list, i, j) > 0) 
                swap(list, i, j);
}

void test_sort() {
    char* list[] = {"Cat", "Elephant", "Dog", "Lion", "Zebra", "Ape"};
    sort (list, 6);
    for (int i = 0; i < 6; i++)
        printf("%s\n", list[i]);
}