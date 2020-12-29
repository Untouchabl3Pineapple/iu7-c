#ifndef __IO_H__

#define __IO_H__

#define _GNU_SOURCE

#include <stdio.h>
#include <string.h>

#include "macrologger.h"
#include "constants.h" 
#include "data_structures.h"
#include "memory_functions.h"
#include "stack_functions.h"
#include "list_functions.h"

#define DELETING_NEW_LINE_IN_FILTER (filter[3] = '\0')

int filter_fill(char *const filter);

int read_line(char **line);

int number_size(int number);

int list_fill(node_t **head);

void list_print(node_t *head);

#endif // __IO_H__
