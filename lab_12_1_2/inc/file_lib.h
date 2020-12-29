#ifndef __FILE_LIB_H__

#define __FILE_LIB_H__

#include <stdio.h>

#include "constants.h"

FILE *file_open(char *const filename);

void file_rewind(FILE *file);

void file_close(FILE *file);

#endif // __FILE_LIB_H__
