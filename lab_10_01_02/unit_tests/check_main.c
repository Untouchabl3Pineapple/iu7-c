#include "../inc/unit_test.h"

Suite *test_polynomial_value_suite(Suite *s);

Suite *test_polynomial_derivative_suite(Suite *s);

Suite *test_polynomial_sum_suite(Suite *s);

Suite *test_polynomial_degree_separation_suite(Suite *s);

Suite *all_suite(void)
{
    Suite *s;
    
    s = suite_create("all_suite");

    test_polynomial_value_suite(s);
    test_polynomial_derivative_suite(s);
    test_polynomial_sum_suite(s);
    test_polynomial_degree_separation_suite(s);

    return s;
}

int main(void)
{
    Suite *s;
    SRunner *runner;
    int exit_code;

    s = all_suite();
    runner = srunner_create(s);
    srunner_run_all(runner, CK_VERBOSE);
    exit_code = srunner_ntests_failed(runner);
    srunner_free(runner);

    return exit_code;
}
