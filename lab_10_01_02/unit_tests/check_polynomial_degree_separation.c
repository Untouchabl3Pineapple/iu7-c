#include "../inc/unit_test.h"

START_TEST(test_polynomial_degree_separation)
{
    node_t *head_test = NULL, *head_test_1 = NULL, *head_test_2 = NULL;
    node_t *head_test_out_1 = NULL, *head_test_out_2 = NULL;
    FILE *file_test_in = fopen("./func_tests/pos_04_in.txt", "r");
    FILE *file_test_out = fopen("./func_tests/pos_04_out.txt", "r");

    fscanf(file_test_in, "%*s");
    for (int coefficient, degree; fscanf(file_test_in, "%d", &coefficient) == 1 \
        && fscanf(file_test_in, "%d", &degree) == 1;)
    {
        push(&head_test, coefficient, degree);
    }
    reverse(&head_test);

    fscanf(file_test_out, "%*s");
    for (int coefficient, degree; fscanf(file_test_out, "%d", &coefficient) == 1 \
        && fscanf(file_test_out, "%d", &degree) == 1;)
    {
        push(&head_test_out_1, coefficient, degree);
    }
    reverse(&head_test_out_1);
    
    fscanf(file_test_out, "%*s");
    fscanf(file_test_out, "%*s");
    for (int coefficient, degree; fscanf(file_test_out, "%d", &coefficient) == 1 \
        && fscanf(file_test_out, "%d", &degree) == 1;)
    {
        push(&head_test_out_2, coefficient, degree);
    }
    reverse(&head_test_out_2);

    polynomial_degree_separation(head_test, &head_test_1, &head_test_2);

    ck_assert_int_eq(is_equal(head_test_1, head_test_out_1) && \
    is_equal(head_test_2, head_test_out_2), TRUE);

    fclose(file_test_in);
    fclose(file_test_out);

    list_free(head_test);
    list_free(head_test_1);
    list_free(head_test_2);
    list_free(head_test_out_1);
    list_free(head_test_out_2);
}
END_TEST

Suite *test_polynomial_degree_separation_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_polynomial_degree_separation);

    suite_add_tcase(s, tc_pos);

    return s;
}
