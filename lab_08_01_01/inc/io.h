#ifndef __IO_H__
#define __IO_H__

#include "macrologger.h"
#include "errors.h" 
#include "data_structures.h"
#include "matrix_allocate_and_free.h"
#include <stdio.h>

int matrix_fill(matrix_t *matrix);
void matrix_result_print(matrix_t *matrix);

#endif // __IO_H__
