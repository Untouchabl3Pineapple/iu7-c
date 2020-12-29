#include "unit.h"

START_TEST(test_multiplication_matrix)
{
    matrix_t matrix_1, matrix_result;

    matrix_1.row = 3;
    matrix_1.column = 3;

    matrix_result.row = 3;
    matrix_result.column = 3;

    allocate_matrix(&matrix_1);
    allocate_matrix(&matrix_result);

    convert_to_single_matrix(&matrix_1);
    convert_to_single_matrix(&matrix_result);

    multiplication(&matrix_1, &matrix_result);

    int flag = 0;
    for (int i = 0; i < matrix_1.row; i++)
    {
        for (int j = 0; j < matrix_1.column; j++)
        {
            if (matrix_1.matrix[i][j] != matrix_result.matrix[i][j])
                flag = 1;
        }
    }

    free_matrix(&matrix_1, matrix_1.row);
    free_matrix(&matrix_result, matrix_result.row);

    ck_assert_int_eq(flag, 0);
}
END_TEST

Suite *test_multiplication_matrix_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_multiplication_matrix);

    suite_add_tcase(s, tc_pos);

    return s;
}
