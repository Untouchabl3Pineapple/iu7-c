#ifndef __MATRIX_CONVERT_H__
#define __MATRIX_CONVERT_H__

#include "macrologger.h"
#include "data_structures.h"
#include "errors.h"
#include "matrix_allocate_and_free.h"
#include <stdio.h>
#include <math.h>

int convert_to_square_matrix(matrix_t *matrix);

void find_max_digit_in_matrix(matrix_t *matrix, int *const row_ind, int *const column_ind);
int delete_matrix_row(matrix_t *matrix, const int row_ind);
int delete_matrix_column(matrix_t *matrix, const int column_ind);

int convert_matrices_single_size(matrix_t *matrix_1, matrix_t *matrix_2);

int find_max_element_in_array(int *const array, const int array_len);
void fill_new_matrix_rows(matrix_t *smaller_matrix, matrix_t *large_matrix);
void fill_new_matrix_columns(matrix_t *smaller_matrix, matrix_t *large_matrix);

void convert_to_single_matrix(matrix_t *matrix);

#endif // __MATRIX_CONVERT_H__
