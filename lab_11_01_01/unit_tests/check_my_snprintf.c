#include "../inc/unit_test.h"

START_TEST(test_1_my_snprintf_d)
{
    char my_vector[100];
    char vector[100];

    int my_rc;
    int rc;

    my_rc = snprintf(my_vector, 80, "%d hundred bucks in Hamit's pocket", 3);
    rc = snprintf(vector, 80, "%d hundred bucks in Hamit's pocket", 3);

    ck_assert_int_eq(my_strncmp(my_vector, vector, my_strlen(my_vector)), 0);
    ck_assert_int_eq(my_rc, rc);
}
END_TEST

START_TEST(test_2_my_snprintf_d)
{
    char my_vector[100];
    char vector[100];

    int my_rc;
    int rc;

    my_rc = snprintf(my_vector, 80, "%d hundred bucks and %d employees", 3, 2);
    rc = snprintf(vector, 80, "%d hundred bucks and %d employees", 3, 2);

    ck_assert_int_eq(my_strncmp(my_vector, vector, my_strlen(my_vector)), 0);
    ck_assert_int_eq(my_rc, rc);
}
END_TEST

START_TEST(test_3_my_snprintf_d)
{
    char my_vector[100];
    char vector[100];

    int my_rc;
    int rc;

    my_rc = snprintf(my_vector, 80, "%d hundred bucks under my pillow", 3);
    rc = snprintf(vector, 80, "%d hundred bucks under my pillow", 3);

    ck_assert_int_eq(my_strncmp(my_vector, vector, my_strlen(my_vector)), 0);
    ck_assert_int_eq(my_rc, rc);
}
END_TEST

START_TEST(test_1_my_snprintf_ld)
{
    char my_vector[100];
    char vector[100];

    int my_rc;
    int rc;

    my_rc = snprintf(my_vector, 80, "%ld hundred bucks in Hamit's pocket", LONG_MAX);
    rc = snprintf(vector, 80, "%ld hundred bucks in Hamit's pocket", LONG_MAX);

    ck_assert_int_eq(my_strncmp(my_vector, vector, my_strlen(my_vector)), 0);
    ck_assert_int_eq(my_rc, rc);
}
END_TEST

START_TEST(test_2_my_snprintf_ld)
{
    char my_vector[100];
    char vector[100];

    int my_rc;
    int rc;

    my_rc = snprintf(my_vector, 80, "%ld hundred bucks and %ld employees", LONG_MIN, LONG_MAX);
    rc = snprintf(vector, 80, "%ld hundred bucks and %ld employees", LONG_MIN, LONG_MAX);

    ck_assert_int_eq(my_strncmp(my_vector, vector, my_strlen(my_vector)), 0);
    ck_assert_int_eq(my_rc, rc);
}
END_TEST

START_TEST(test_3_my_snprintf_ld)
{
    char my_vector[100];
    char vector[100];

    int my_rc;
    int rc;

    my_rc = snprintf(my_vector, 80, "%ld hundred bucks under my pillow", LONG_MIN);
    rc = snprintf(vector, 80, "%ld hundred bucks under my pillow", LONG_MIN);

    ck_assert_int_eq(my_strncmp(my_vector, vector, my_strlen(my_vector)), 0);
    ck_assert_int_eq(my_rc, rc);
}
END_TEST

START_TEST(test_1_my_snprintf_c)
{
    char my_vector[100];
    char vector[100];

    int my_rc;
    int rc;

    my_rc = snprintf(my_vector, 80, "%c hundred bucks in Hamit's pocket", '3');
    rc = snprintf(vector, 80, "%c hundred bucks in Hamit's pocket", '3');

    ck_assert_int_eq(my_strncmp(my_vector, vector, my_strlen(my_vector)), 0);
    ck_assert_int_eq(my_rc, rc);
}
END_TEST

START_TEST(test_2_my_snprintf_c)
{
    char my_vector[100];
    char vector[100];

    int my_rc;
    int rc;

    my_rc = snprintf(my_vector, 80, "%c hundred bucks and %c employees", '3', '2');
    rc = snprintf(vector, 80, "%c hundred bucks and %c employees", '3', '2');

    ck_assert_int_eq(my_strncmp(my_vector, vector, my_strlen(my_vector)), 0);
    ck_assert_int_eq(my_rc, rc);
}
END_TEST

START_TEST(test_3_my_snprintf_c)
{
    char my_vector[100];
    char vector[100];

    int my_rc;
    int rc;

    my_rc = snprintf(my_vector, 80, "%c hundred bucks under my pillow", '3');
    rc = snprintf(vector, 80, "%c hundred bucks under my pillow", '3');

    ck_assert_int_eq(my_strncmp(my_vector, vector, my_strlen(my_vector)), 0);
    ck_assert_int_eq(my_rc, rc);
}
END_TEST

Suite *test_my_snprintf_suite(Suite *s)
{
    TCase *tc_pos;

    tc_pos = tcase_create("positives");
    
    tcase_add_test(tc_pos, test_1_my_snprintf_d);
    tcase_add_test(tc_pos, test_2_my_snprintf_d);
    tcase_add_test(tc_pos, test_3_my_snprintf_d);

    tcase_add_test(tc_pos, test_1_my_snprintf_ld);
    tcase_add_test(tc_pos, test_2_my_snprintf_ld);
    tcase_add_test(tc_pos, test_3_my_snprintf_ld);

    tcase_add_test(tc_pos, test_1_my_snprintf_c);
    tcase_add_test(tc_pos, test_2_my_snprintf_c);
    tcase_add_test(tc_pos, test_3_my_snprintf_c);

    suite_add_tcase(s, tc_pos);

    return s;
}
