#ifndef IO_H
#define IO_H

#include "../inc/macrologger.h"
#include <stdio.h>

#define OK 0
#define ARGS_ERROR 1
#define FILE_OPEN_ERROR 2

#define INPUT_FILE_NAME_SIZE 20
#define OUTPUT_FILE_NAME_SIZE 20
#define FILTR_SIZE 20

#define ARGS_LOWER_LIMIT 3
#define ARGS_UPPER_LIMIT 4

int parse_args(const int agrc, const char **argv, int *const args_number, \
char *const in_file_name, char *const out_file_name, char *const filtr);
int scan_file_len(FILE *const f, int *const file_len);
void fill_array(FILE *const f, int *const array);
//void print_array(const int *pb_filtr_array, const int *pe_filtr_array);
void fill_file(FILE *const f, const int *pb_filtr_array, const int *pe_filtr_array);

#endif // IO_H
