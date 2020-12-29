#ifndef __IO_H__

#define __IO_H__

#include <stdio.h>
#include <string.h>

#include "macrologger.h"
#include "constants.h" 
#include "data_structures.h"
#include "list_functions.h"

int parse_args(const int argc, const char **const argv, int *const args_number, \
char *filename_in, char *filename_out);

int fill_data(node_t **head, int *const number_del, FILE *file_in);

void fill_file(FILE *file_out, node_t *head);

void list_print(node_t *head);

#endif // __IO_H__
