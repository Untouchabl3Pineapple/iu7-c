#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 257
#define WORD_SIZE 17

#define ROW 16
#define COLUMN 17

#define LEN_ROW_ERROR 1
#define LEN_WORD_ERROR 2
#define OK 0

#define TRUE 0
#define FALSE 1

void print_matrix(char (*m)[COLUMN], const int ind);
int compare(const void *a, const void *b);
int is_dublicate(char (*m)[COLUMN], char *const word, const int ind);
int condition_test(char *const str, char (*m)[COLUMN], int *ind);

#endif // FUNCTIONS_H
