#include "functions.h"

int main(int argc, char **argv)
{
    FILE *f = fopen(argv[1], "r");
    double min, max, average;
    int numbers_counter = 0;
    int test = condition_test(f);
    
    if (test != OK)
        return test;
    if (fclose(f) == EOF)
        return FILE_CLOSE_ERROR;
    
    f = fopen(argv[1], "r");
    find_max_numb(f, &max);
    rewind(f);
    find_min_numb(f, &min);
    AVERAGE;
    rewind(f);
    find_number_of_numbers(f, average, &numbers_counter);
    printf("%d\n", numbers_counter);
    
    if (fclose(f) == EOF)
        return FILE_CLOSE_ERROR;
    
    return OK;
}
