#ifndef __IO_LIB_H__

#define __IO_LIB_H__

#include <stdio.h>

#include "macrologger.h"
#include "constants.h"

int parse_args(const int agrc, const char **argv, int *const args_number, \
char *const in_file_name, char *const out_file_name, char *const filtr);

int scan_file_len(FILE *const f, int *const file_len);

void fill_array(FILE *const f, int *const array);

void fill_file(FILE *const f, const int *pb_filtr_array, const int *pe_filtr_array);

#endif // __IO_LIB_H__
