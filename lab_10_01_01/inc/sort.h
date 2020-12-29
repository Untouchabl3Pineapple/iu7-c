#ifndef __SORT_H__

#define __SORT_H__

#include "constants.h" 
#include "data_structures.h"
#include "io.h"
#include "memory_functions.h"

int compare(const void *x, const void *y);

node_t *sort(node_t *head, int (*comparator)(const void *, const void *));

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

#endif // __SORT_H__
