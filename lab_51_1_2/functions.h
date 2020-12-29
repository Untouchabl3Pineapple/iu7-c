#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>

#define AVERAGE average = (min + max) / 2
#define FILE_READING_ERROR 1
#define FILE_CLOSE_ERROR 2

#define OK 0

int condition_test(FILE *f);
void find_max_numb(FILE *f, double *const max);
void find_min_numb(FILE *f, double *const min);
void find_number_of_numbers(FILE *f, const double average, int *const numbers_counter);

#endif // FUNCTIONS_H
