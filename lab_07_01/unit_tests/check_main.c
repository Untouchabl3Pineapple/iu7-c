#include "unit.h"

Suite *all_suite(void)
{
    Suite *s;
    
    s = suite_create("all_suite");
    parse_args_suite(s);
    key_suite(s);

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
