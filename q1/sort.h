#pragma once

// TODO 7: Add declaration of generic sort procedure by uncommenting next line and replacing ... with appropriate parameter(s)
// void sort (void* list, int length, void* (*));
void sort (
    void* list,
    int length,
    int (*cmp) (void*, int a, int b),
    void (*swp) (void* list, int a, int b)
);

int compareint(void* listv, int a, int b);
int comparestr(void* listv, int a, int b);

void swapint(void* listv, int a, int b);
void swapstr(void* listv, int a, int b);

void test_sort();
void test_compare();