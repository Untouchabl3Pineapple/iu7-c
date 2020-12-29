#ifndef __STR_FUNCTIONS_H__

#define __STR_FUNCTIONS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "macrologger.h"
#include "constants.h"
#include "data_structures.h"

char *my_strncat(char *destptr, const char *srcptr, const size_t len);

size_t my_strlen(const char *str);

int number_size(long number, char *const filter);

char *integer_to_string(long number, int *const buf_size);

int my_strncmp(const char *str1, const char *str2, size_t n);

#endif // __STR_FUNCTIONS_H__
