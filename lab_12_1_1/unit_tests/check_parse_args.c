#include "unit.h"

START_TEST(test_parse_args_bad_argc_above_upper_limit)
{
    int rc;
    int args_number;
    char in_file_name[] = {"iu.txt"};
    char out_file_name[] = {"zavod.txt"};
    char filtr[] = {"kfc.txt"};
    const char *argv[] = {"Hello", "IU7", "Hello", "IU7"};

    rc = parse_args(2, argv, &args_number, in_file_name, out_file_name, filtr);

    ck_assert_int_eq(rc, ARGS_ERROR);
}
END_TEST

START_TEST(test_parse_args_bad_argc_under_lower_limit)
{
    int rc;
    int args_number;
    char in_file_name[] = {"iu.txt"};
    char out_file_name[] = {"zavod.txt"};
    char filtr[] = {"kfc.txt"};
    const char *argv[] = {"Hello", "IU7", "Hello", "IU7"};

    rc = parse_args(5, argv, &args_number, in_file_name, out_file_name, filtr);

    ck_assert_int_eq(rc, ARGS_ERROR);
}
END_TEST

START_TEST(test_parse_args_standart_parsing_without_filter)
{
    int rc;
    int args_number;
    char in_file_name[] = {"iu.txt"};
    char out_file_name[] = {"zavod.txt"};
    char filtr[] = {"kfc.txt"};
    const char *argv[] = {"Hello", "IU7", "Hello", "IU7"};

    rc = parse_args(3, argv, &args_number, in_file_name, out_file_name, filtr);

    ck_assert_int_eq(rc, OK);
}
END_TEST

START_TEST(test_parse_args_standart_parsing_with_filter)
{
    int rc;
    int args_number;
    char in_file_name[] = {"iu.txt"};
    char out_file_name[] = {"zavod.txt"};
    char filtr[] = {"kfc.txt"};
    const char *argv[] = {"Hello", "IU7", "Hello", "f"};

    rc = parse_args(4, argv, &args_number, in_file_name, out_file_name, filtr);

    ck_assert_int_eq(rc, OK);
}
END_TEST

Suite *parse_args_suite(Suite *s)
{
    TCase *tc_neg;
    TCase *tc_pos;

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_parse_args_bad_argc_above_upper_limit);
    tcase_add_test(tc_neg, test_parse_args_bad_argc_under_lower_limit);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_parse_args_standart_parsing_without_filter);
    tcase_add_test(tc_pos, test_parse_args_standart_parsing_with_filter);

    suite_add_tcase(s, tc_pos);

    return s;
}
