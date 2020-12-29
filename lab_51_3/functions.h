#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TRUE 1

#define OK 0
#define NUMBER_OF_ELEMENTS_ERROR 1
#define FILE_READING_ERROR 2
#define ARGC_ERROR 3
#define FILE_CLOSE_ERROR 4

int create_file(FILE *f, const int numb);
int print_file(FILE *f);
int get_number_by_pos(FILE *f, int position);
void put_number_by_pos(FILE *f, int position, int number);
size_t file_size(FILE *f);
int sort(FILE *f);

#endif // FUNCTIONS_H
