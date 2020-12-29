#ifndef __MY_SNPRINTF_H__

#define __MY_SNPRINTF_H__

#include <stdio.h>
#include <stdarg.h>

#include "macrologger.h"
#include "constants.h"
#include "data_structures.h"
#include "str_functions.h"

#define BUFFER_INIT (buffer[0] = '\0')

int get_size_end_format(const char *format, va_list arg);

int my_snprintf(char *buffer, int buf_size, const char *format, ...);

#endif // __MY_SNPRINTF_H__
