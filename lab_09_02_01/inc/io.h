#ifndef __IO_H__
#define __IO_H__

#include <stdio.h>
#include <string.h>

#include "macrologger.h"
#include "data_structures.h"
#include "errors.h"
#include "data_memory_functions.h"

#define FILE_NAME_SIZE 100
#define FILTER_SIZE 100

#define LOWER_LIMIT_ARGC 2
#define UPPER_LIMIT_ARGC 3

int parse_args(const int argc, char **const argv, int *const args_number, \
char *filename, char *filter);

int input_inform(item_t *items_array, const int items_len, FILE *file);

void print_structure(const item_t *const items_array, const int index);

void print_inform(const item_t *const items_array, const int items_len, \
const int args_number, char *const filter);

int is_empty(FILE *file);

#endif // __IO_H__
