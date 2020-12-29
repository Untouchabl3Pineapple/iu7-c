#include "../inc/io_lib.h"

int parse_args(const int argc, const char **argv, int *const args_number, \
char *const in_file_name, char *const out_file_name, char *const filtr)
{
    if (argc < ARGS_LOWER_LIMIT || argc > ARGS_UPPER_LIMIT)
        return ARGS_ERROR;

    *args_number = argc;
    strcpy(in_file_name, *(argv + 1));
    strcpy(out_file_name, *(argv + 2));
    
    if (argc == ARGS_UPPER_LIMIT)
    {
        if (strcmp(*(argv + 3), "f") != 0)
            return ARGS_ERROR;

        strcpy(filtr, *(argv + 3));  
    }

    return OK;
}

int scan_file_len(FILE *const f, int *const file_len)
{
    for (int temp_digit; fscanf(f, "%d", &temp_digit) == 1;)
    {
        (*file_len)++;
    }

    rewind(f);

    return *file_len;
}

void fill_array(FILE *const f, int *array)
{
    for (; fscanf(f, "%d", array++) == 1;);

    rewind(f);
}

void fill_file(FILE *const f, const int *pb_filtr_array, const int *pe_filtr_array)
{
    for (; pb_filtr_array < pe_filtr_array; pb_filtr_array++)
    {
        fprintf(f, "%d ", *pb_filtr_array);
    }
}
