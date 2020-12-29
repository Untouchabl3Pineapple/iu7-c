#include "../inc/unit_test.h"

START_TEST(test_polynomial_derivative)
{
    node_t *head_test_in = NULL, *head_test_out = NULL;
    FILE *file_test_in = fopen("./func_tests/pos_02_in.txt", "r");
    FILE *file_test_out = fopen("./func_tests/pos_02_out.txt", "r");

    fscanf(file_test_in, "%*s");
    for (int coefficient, degree; fscanf(file_test_in, "%d", &coefficient) == 1 \
        && fscanf(file_test_in, "%d", &degree) == 1;)
    {
        push(&head_test_in, coefficient, degree);
    }
    reverse(&head_test_in);

    fscanf(file_test_out, "%*s");
    for (int coefficient, degree; fscanf(file_test_out, "%d", &coefficient) == 1 \
        && fscanf(file_test_out, "%d", &degree) == 1;)
    {
        push(&head_test_out, coefficient, degree);
    }
    reverse(&head_test_out);

    node_t *tail = polynomial_derivative(head_test_in);

    if (tail != NULL)
        del_node_by_pointer(head_test_in, tail);

    ck_assert_int_eq(is_equal(head_test_in, head_test_out), TRUE);

    fclose(file_test_in);
    fclose(file_test_out);

    list_free(head_test_in);
    list_free(head_test_out);
}
END_TEST

Suite *test_polynomial_derivative_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_polynomial_derivative);

    suite_add_tcase(s, tc_pos);

    return s;
}
