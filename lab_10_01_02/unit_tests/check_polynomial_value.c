#include "../inc/unit_test.h"

START_TEST(test_polynomial_value)
{
    int var;
    node_t *head_test = NULL;
    FILE *file_test = fopen("./func_tests/pos_01_in.txt", "r");

    fscanf(file_test, "%*s");

    for (int coefficient, degree; fscanf(file_test, "%d", &coefficient) == 1 \
        && fscanf(file_test, "%d", &degree) == 1;)
    {
        push(&head_test, coefficient, degree);
    }
    reverse(&head_test);

    fscanf(file_test, "%d", &var);

    ck_assert_int_eq(polynomial_value(head_test, var), 197);

    fclose(file_test);

    list_free(head_test);
}
END_TEST

Suite *test_polynomial_value_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_polynomial_value);

    suite_add_tcase(s, tc_pos);

    return s;
}
