#include "functions.h"

int main(void)
{
    char str[STR_SIZE] = { 0 };
    char m[ROW][COLUMN];
    int ind = 0;
    int test;
    
    test = condition_test(str, m, &ind);
    if (test != OK)
        return test;
    
    qsort(m, ind, COLUMN, compare);
    print_matrix(m, ind);
 
    return OK;
}

