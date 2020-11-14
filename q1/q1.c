#include <stdlib.h>
#include <stdio.h>
#include "foreach.h"
#include "sort.h"
#include "integer_list.h"
#include "integer_tree.h"

/**
 * CPSC 213 Assignment 8, Question 1 Test Harness
 */

void print(void* ipv) {
    int* ip = ipv;
    printf("%d\n", *ip);
}

int sm, mn, mx;

void sum(void* ipv) {
    int* ip = ipv;
    sm += *ip;
}

void min(void* ipv) {
    int* ip = ipv;
    if (*ip < mn) {
        mn = *ip;
    }
}

void max(void* ipv) {
    int* ip = ipv;
    if (*ip > mx) {
      mx = *ip;
    }
}

void test_integer_tree(int* vals, int n) {
    printf("Tree:\n");
    struct it_tree* it = it_new();
    for (int i = 0; i < n; i++)
        it_add(it, vals [i]);

    printf("Order List of Values:\n");
    // TODO 1: Replace next 6 lines with call to foreach
    foreach(it, it_iterator, it_has_next, it_get_next, it_delete_iterator, &print);
    // TODO 2: see foreach.c

    // TODO 3: use foreach to compute sum, min, and max of values in tree
    sm = 0, mn = 99999999, mx = -1;
    foreach(it, it_iterator, it_has_next, it_get_next, it_delete_iterator, &min);
    foreach(it, it_iterator, it_has_next, it_get_next, it_delete_iterator, &max);
    foreach(it, it_iterator, it_has_next, it_get_next, it_delete_iterator, &sum);
    printf ("Stats: sum %d min %d max %d\n", sm, mn, mx);

    it_delete(it);
}

// void test_int_list(int* vals, int n) {
//     printf("Integer List Tests\n");
//     struct il_list* il = il_new(n);
//     for (int i = 0; i < n; i++)
//         il_add(il, vals [i]);
//     for (int i = 0; i < n; i++)
//         printf("%d\n", il->data [i]);
// }

void test_integer_list(int* vals, int n) {
    printf("Integer List\n");
    struct il_list* il = il_new(n);
    for (int i = 0; i < n; i++)
        il_add(il, vals [i]);

    // TODO 4 and 5: see integer_list.c

    printf("Unordered List of Values:\n");
    // TODO 6: use foreach to print unsorted (i.e., input-order) list of values
    foreach(il, il_iterator, il_has_next, il_get_next, il_delete_iterator, &print);

    // TODO 7: see sort.c and sort.h
    // TODO 8: see integer_list.c

    printf("Ordered List of Values:\n");
    // TODO 9: use il_sort and then foreach to print sorted list of values
    il_sort(il);
    foreach(il, il_iterator, il_has_next, il_get_next, il_delete_iterator, &print);

    // TODO 10: use foreach to compute sum, min, and max of values in list\
    mn = 99999999, mx = -1;
    sm = 0;
    foreach(il, il_iterator, il_has_next, il_get_next, il_delete_iterator, &min);
    foreach(il, il_iterator, il_has_next, il_get_next, il_delete_iterator, &max);
    foreach(il, il_iterator, il_has_next, il_get_next, il_delete_iterator, &sum);
    printf ("Stats: sum %d min %d max %d\n", sm, mn, mx);

    il_delete(il);
}


int main(int argc, char** argv) {
    int n = argc - 1;
    int vals[n];
    for (int i=1; i<n + 1; i++)
        vals[i-1] = atoi(argv[i]);
    test_integer_tree(vals, n);
    test_integer_list(vals, n);
    // test_sort();
}