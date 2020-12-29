#include "functions.h"

int condition_test(FILE *f)
{
    double temp;
    int counter = 0;
    
    if (f == NULL)
        return FILE_READING_ERROR;
    
    while (fscanf(f, "%lf", &temp) == 1)
        counter++;
        
    if (counter < 2)
        return FILE_READING_ERROR;
        
    if (feof(f) != 0)
        return OK;
    return FILE_READING_ERROR;
}

void find_max_numb(FILE *f, double *const max)
{
    double temp;
    
    fscanf(f, "%lf", max);
    while (fscanf(f, "%lf", &temp) == 1)
        if (temp > *max)
            *max = temp;
}

void find_min_numb(FILE *f, double *const min)
{
    double temp;
    
    fscanf(f, "%lf", min);
    while (fscanf(f, "%lf", &temp) == 1)
        if (temp < *min)
            *min = temp;
}

void find_number_of_numbers(FILE *f, const double average, int *const numbers_counter)
{
    double temp;

    while (fscanf(f, "%lf", &temp) == 1)
        if (temp > average)
            (*numbers_counter)++;
}
