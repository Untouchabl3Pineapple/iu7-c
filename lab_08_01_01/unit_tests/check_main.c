#include "unit.h"

Suite *all_suite(void)
{
    Suite *s;
    
    s = suite_create("all_suite");
    test_delete_matrix_row_suite(s);
    test_delete_matrix_column_suite(s);
    test_fill_new_matrix_rows_suite(s);
    test_fill_new_matrix_columns_suite(s);
    test_multiplication_matrix_suite(s);

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
