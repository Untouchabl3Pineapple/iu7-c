#include "unit.h"

START_TEST(test_fill_new_matrix_columns)
{
    matrix_t matrix_1, matrix_2;

    matrix_1.row = 3;
    matrix_1.column = 2;

    matrix_2.row = 3;
    matrix_2.column = 3;

    allocate_matrix(&matrix_1);
    for (int i = 0; i < matrix_1.row; i++)
    {
        for (int j = 0; j < matrix_1.column; j++)
        {
            matrix_1.matrix[i][j] = i + 1;
        }
    }

    allocate_matrix(&matrix_2);
    for (int i = 0; i < matrix_2.row; i++)
    {
        for (int j = 0; j < matrix_2.column; j++)
        {
            matrix_2.matrix[i][j] = i + 1;
        }
    }

    reallocate_matrix(&matrix_1, &matrix_2);
    fill_new_matrix_columns(&matrix_1, &matrix_2);

    int flag = 0;
    if (matrix_1.matrix[0][2] != 1 || matrix_1.matrix[1][2] != 2 || matrix_1.matrix[2][2] != 3)
        flag = 1;

    free_matrix(&matrix_1, matrix_1.row);
    free_matrix(&matrix_2, matrix_2.row);

    ck_assert_int_eq(flag, 0);
}
END_TEST

Suite *test_fill_new_matrix_columns_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_fill_new_matrix_columns);

    suite_add_tcase(s, tc_pos);

    return s;
}
