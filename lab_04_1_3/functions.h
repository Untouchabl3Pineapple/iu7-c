#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>

#define STR_SIZE 257
#define WORD_SIZE 17
#define WORDS_LIMIT 2

#define ROW 16
#define COLUMN 17

#define LEN_ROW_ERROR 1
#define LEN_WORD_ERROR 2
#define ONE_WORD_ERROR 3
#define SAME_WORDS_ERROR 4
#define OK 0

#define TRUE 0
#define FALSE 1

int is_same_words(char (*m)[COLUMN], const int ind);
void chr_sort(char *temp_str, char *sorted_str);
void str_form(char (*m)[COLUMN], char *const new_str, const int ind);
int condition_test(char *const str, char (*m)[COLUMN], int *ind);

#endif // FUNCTIONS_H
