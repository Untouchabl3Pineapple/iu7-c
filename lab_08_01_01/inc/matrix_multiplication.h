#ifndef __MATRIX_MULTIPLICATION_H__
#define __MATRIX_MULTIPLICATION_H__

#include "macrologger.h"
#include "errors.h" 
#include "data_structures.h"
#include "matrix_allocate_and_free.h"
#include "matrix_convert.h"
#include <stdio.h>

int multiplication(matrix_t *matrix, matrix_t *matrix_result);
int matrix_multiplication(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *matrix_result);

#endif // __MATRIX_MULTIPLICATION_H__
