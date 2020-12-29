#ifndef __IO_LIB_H__

#define __IO_LIB_H__

#include <stdio.h>

#include "data_structures.h"
#include "constants.h"

int fill_data(vector_t vector, FILE *f);

char *fill_filename(char *const filename);

void print_vector(vector_t vector);

#endif // __IO_LIB_H__
