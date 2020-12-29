#ifndef __MATRIX_ALLOCATE_AND_FREE_H__
#define __MATRIX_ALLOCATE_AND_FREE_H__

#include "errors.h" 
#include "data_structures.h"
#include <stdlib.h>

int allocate_matrix(matrix_t *matrix);
int reallocate_matrix(matrix_t *smaller_matrix, matrix_t *large_matrix);
void free_matrix(matrix_t *matrix, int index);

#endif // __MATRIX_ALLOCATE_AND_FREE_H__
