#include "unit.h"

START_TEST(test_delete_matrix_row)
{
    matrix_t matrix_1, matrix_2;

    matrix_1.row = 3;
    matrix_1.column = 3;

    matrix_2.row = 2;
    matrix_2.column = 3;

    allocate_matrix(&matrix_1);
    for (int i = 0; i < matrix_1.row; i++)
    {
        for (int j = 0; j < matrix_1.column; j++)
        {
            matrix_1.matrix[i][j] = i;
        }
    }

    allocate_matrix(&matrix_2);
    for (int i = 0; i < matrix_2.row; i++)
    {
        for (int j = 0; j < matrix_2.column; j++)
        {
            if (i == 0)
                matrix_2.matrix[i][j] = 1;
            if (i == 1)
                matrix_2.matrix[i][j] = 2;
        }
    }

    delete_matrix_row(&matrix_1, 0);

    int flag = 0;
    for (int i = 0; i < matrix_1.row; i++)
    {
        for (int j = 0; j < matrix_1.column; j++)
        {
            if (matrix_1.matrix[i][j] != matrix_2.matrix[i][j])
                flag = 1;
        }
    }

    free_matrix(&matrix_1, matrix_1.row);
    free_matrix(&matrix_2, matrix_2.row);

    ck_assert_int_eq(flag, 0);
}
END_TEST

Suite *test_delete_matrix_row_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_delete_matrix_row);

    suite_add_tcase(s, tc_pos);

    return s;
}
