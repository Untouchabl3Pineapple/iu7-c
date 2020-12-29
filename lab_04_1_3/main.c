#include "functions.h"

int main(void)
{
    char str[STR_SIZE] = { 0 };
    char m[ROW][COLUMN];
    char new_str[STR_SIZE] = { 0 };
    int ind = 0;
    int test;
    
    test = condition_test(str, m, &ind);
    if (test != OK)
        return test;
    
    str_form(m, new_str, ind);
    printf("Result: %s\n", new_str);

    return OK;
}
