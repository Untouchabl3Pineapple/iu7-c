#ifndef __LOAD_DYNLIB_H__

#define __LOAD_DYNLIB_H__

#include <stdio.h>
#include <dlfcn.h>

#include "constants.h"

int (*parse_args)(const int agrc, const char **argv, int *const args_number, \
char *const in_file_name, char *const out_file_name, char *const filtr);

int (*scan_file_len)(FILE *const f, int *const file_len);

void (*fill_array)(FILE *const f, int *const array);

void (*fill_file)(FILE *const f, const int *pb_filtr_array, const int *pe_filtr_array);

int (*compare)(const void *x, const void *y);

void (*mysort)(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));

int (*key)(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst);

int load_library(void);

#endif // __LOAD_DYNLIB_H__