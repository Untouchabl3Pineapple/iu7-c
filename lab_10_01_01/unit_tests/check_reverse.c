#include "../inc/unit_test.h"

START_TEST(test_reverse)
{
    int number_del;
    node_t *head_test_in = NULL, *head_test_out = NULL;
    FILE *file_test_in = fopen("./unit_tests/tests/reverse_pos_01_in.txt", "r");
    FILE *file_test_out = fopen("./unit_tests/tests/reverse_pos_01_out.txt", "r");

    fill_data(&head_test_in, &number_del, file_test_in);

    for (int number, *data; fscanf(file_test_out, "%d", &number) == 1;)
    {
        data = (int *)malloc(sizeof(int));
        *data = number;

        push(&head_test_out, data);
    }
    head_test_out = reverse(head_test_out);

    head_test_in = reverse(head_test_in);

    ck_assert_int_eq(is_equal(head_test_in, head_test_out), TRUE);

    fclose(file_test_in);
    fclose(file_test_out);

    list_free(head_test_in);
    list_free(head_test_out);
}
END_TEST

Suite *test_reverse_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_reverse);

    suite_add_tcase(s, tc_pos);

    return s;
}
