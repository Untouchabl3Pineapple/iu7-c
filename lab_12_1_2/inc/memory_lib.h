#ifndef __MEMORY_LIB_H__

#define __MEMORY_LIB_H__

#include <stdlib.h>

#include "data_structures.h"
#include "constants.h"

int *vector_alloc(int *vector, const int len);

void vector_free(int *vector);

#endif // __MEMORY_LIB_H__
