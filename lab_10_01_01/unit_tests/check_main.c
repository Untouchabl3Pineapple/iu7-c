#include "../inc/unit_test.h"

Suite *test_pop_front_suite(Suite *s);

Suite *test_pop_back_suite(Suite *s);

Suite *test_reverse_suite(Suite *s);

Suite *test_sort_suite(Suite *s);

Suite *all_suite(void)
{
    Suite *s;
    
    s = suite_create("all_suite");

    test_pop_front_suite(s);
    test_pop_back_suite(s);
    test_reverse_suite(s);
    test_sort_suite(s);

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
