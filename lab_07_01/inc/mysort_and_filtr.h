#ifndef MYSORT_AND_FILTR_H
#define MYSORT_AND_FILTR_H

#include "../inc/macrologger.h"
#include <stdlib.h>
#include <stdio.h>

#define OK 0
#define EMPTY_FILTR_ARRAY 3
#define MEMORY_ALLOCATION_ERROR 4
#define CLOSE_FILE_ERROR 5
#define EMPTY_SRC_ARRAY_ERROR 6
#define NO_ELEMENTS_BETWEEN_ERROR 7

int compare(const void *x, const void *y);
void mysort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif // MYSORT_AND_FILTR_H
