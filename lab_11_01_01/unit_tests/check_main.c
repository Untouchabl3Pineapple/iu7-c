#include "../inc/unit_test.h"

Suite *test_my_snprintf_suite(Suite *s);

Suite *all_suite(void)
{
    Suite *s;
    
    s = suite_create("all_suite");

    test_my_snprintf_suite(s);

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