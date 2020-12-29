#include "unit.h"

START_TEST(test_filter_bad_filter_array_len_no_digits_between_min_max)
{
    int array[3] = {1, -2, 3};
    int *pb_dst, *pe_dst;
    int rc;

    pb_dst = (int *) malloc(ARRAY_SIZE * sizeof(int));

    rc = key(array, array + 3, pb_dst, &pe_dst);

    free(pb_dst);

    ck_assert_int_eq(rc, NO_ELEMENTS_BETWEEN_ERROR);
}
END_TEST

START_TEST(test_filter_bad_filter_array_len_one_digit_in_array)
{
    int array[1] = { 1 };
    int *pb_dst, *pe_dst;
    int rc;

    pb_dst = (int *) malloc(ARRAY_SIZE * sizeof(int));

    rc = key(array, array + 1, pb_dst, &pe_dst);

    free(pb_dst);

    ck_assert_int_eq(rc, EMPTY_SRC_ARRAY_ERROR);
}
END_TEST

START_TEST(test_filter_correct_filter_array_len)
{
    int array[3] = {1, 2, 3};
    int *pb_dst, *pe_dst;
    int rc;

    pb_dst = (int *) malloc(ARRAY_SIZE * sizeof(int));

    rc = key(array, array + 3, pb_dst, &pe_dst);

    free(pb_dst);

    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite *key_suite(Suite *s)
{
    TCase *tc_neg;
    TCase *tc_pos;
    
    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_filter_bad_filter_array_len_no_digits_between_min_max);
    tcase_add_test(tc_neg, test_filter_bad_filter_array_len_one_digit_in_array);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_filter_correct_filter_array_len);

    suite_add_tcase(s, tc_pos);

    return s;
}
