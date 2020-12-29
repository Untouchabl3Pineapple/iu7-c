#ifndef __UNIT_H__
#define __UNIT_H__

#include <check.h>
#include "../inc/errors.h"
#include "../inc/data_structures.h"
#include "../inc/io.h"
#include "../inc/matrix_allocate_and_free.h"
#include "../inc/matrix_convert.h"
#include "../inc/matrix_multiplication.h"

Suite *test_delete_matrix_row_suite(Suite *s);
Suite *test_delete_matrix_column_suite(Suite *s);
Suite *test_fill_new_matrix_rows_suite(Suite *s);
Suite *test_fill_new_matrix_columns_suite(Suite *s);
Suite *test_multiplication_matrix_suite(Suite *s);

#endif // __UNIT_H__
