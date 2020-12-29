#include "../inc/unit_test.h"

START_TEST(test_pop_front)
{
    int number_del;
    node_t *head_test_in = NULL, *head_test_out = NULL;
    FILE *file_test_in = fopen("./unit_tests/tests/pop_front_pos_01_in.txt", "r");
    FILE *file_test_out = fopen("./unit_tests/tests/pop_front_pos_01_out.txt", "r");

    fill_data(&head_test_in, &number_del, file_test_in);

    for (int number, *data; fscanf(file_test_out, "%d", &number) == 1;)
    {
        data = (int *)malloc(sizeof(int));
        *data = number;

        push(&head_test_out, data);
    }
    head_test_out = reverse(head_test_out);

    free(pop_front(&head_test_in));

    ck_assert_int_eq(is_equal(head_test_in, head_test_out), TRUE);

    fclose(file_test_in);
    fclose(file_test_out);

    list_free(head_test_in);
    list_free(head_test_out);
}
END_TEST

Suite *test_pop_front_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_pop_front);

    suite_add_tcase(s, tc_pos);

    return s;
}
