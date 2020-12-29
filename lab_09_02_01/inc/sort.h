#ifndef __SORT_H__
#define __SORT_H__

#include "data_structures.h"

#define DENSITY(weight, volume) ((weight) / (volume))

void insertion_sort(item_t *items_array, const int items_len);

#endif // __SORT_H__
