#include "../inc/unit_test.h"

START_TEST(test_polynomial_sum)
{
    node_t *head_test_1 = NULL, *head_test_2 = NULL;
    node_t *head_test_sum = NULL, *head_test_out = NULL;
    FILE *file_test_in = fopen("./func_tests/pos_03_in.txt", "r");
    FILE *file_test_out = fopen("./func_tests/pos_03_out.txt", "r");

    fscanf(file_test_in, "%*s");
    for (int coefficient, degree; fscanf(file_test_in, "%d", &coefficient) == 1 \
        && fscanf(file_test_in, "%d", &degree) == 1;)
    {
        push(&head_test_1, coefficient, degree);
    }
    reverse(&head_test_1);

    for (int coefficient, degree; fscanf(file_test_in, "%d", &coefficient) == 1 \
        && fscanf(file_test_in, "%d", &degree) == 1;)
    {
        push(&head_test_2, coefficient, degree);
    }
    reverse(&head_test_2);
    
    fscanf(file_test_out, "%*s");
    for (int coefficient, degree; fscanf(file_test_out, "%d", &coefficient) == 1 \
        && fscanf(file_test_out, "%d", &degree) == 1;)
    {
        push(&head_test_out, coefficient, degree);
    }
    reverse(&head_test_out);

    polynomial_sum(head_test_1, head_test_2, &head_test_sum);

    ck_assert_int_eq(is_equal(head_test_sum, head_test_out), TRUE);

    fclose(file_test_in);
    fclose(file_test_out);

    list_free(head_test_1);
    list_free(head_test_2);
    list_free(head_test_sum);
    list_free(head_test_out);
}
END_TEST

Suite *test_polynomial_sum_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_polynomial_sum);

    suite_add_tcase(s, tc_pos);

    return s;
}
