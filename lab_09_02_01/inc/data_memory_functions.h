#ifndef __DATA_MEMORY_FUNCTIONS_H__
#define __DATA_MEMORY_FUNCTIONS_H__

#define _GNU_SOURCE

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>

#include "macrologger.h"
#include "data_structures.h"
#include "errors.h"
#include "io.h"

int array_allocate(item_t **items_array, int *const items_len, FILE *file);

int string_allocate(char **title, FILE *file);

void data_free(item_t **items_array, int index);

#endif // __DATA_MEMORY_FUNCTIONS_H__
