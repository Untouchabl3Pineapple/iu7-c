#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define NAME_SIZE 31
#define MANUFACTURER_SIZE 16

#define TRUE 1
#define FALSE 0

#define OK 0
#define FILE_READING_ERROR 1
#define STR_NOT_FOUND 2
#define INPUT_ERROR 3
#define FILE_CLOSE_ERROR 4
#define ARGC_ERROR 53

typedef struct
{
    char name[NAME_SIZE];
    char manufacturer[MANUFACTURER_SIZE];
    uint32_t price;
    uint32_t amount;
} shop;

size_t file_size(FILE *f);
void get_structure(FILE *f, const int position, shop *product);
void put_structure(FILE *f, const int position, shop *product);

int sort_file(FILE *f_in, shop *product, shop *temp_product);
int output_in_file(FILE *f_in, FILE *f_out, shop *product);

int is_substr_in_name(char *const substr, shop *product);
int print_product_with_exception(FILE *f_in, char *const substr, shop *product);

int product_input(FILE *f_in, shop *temp_product);
int insert_in_file(FILE *f_in, shop *product, shop *temp_product);

#endif // FUNCTIONS_H
