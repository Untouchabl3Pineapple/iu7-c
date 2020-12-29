#include <stdlib.h>

#include "../inc/macrologger.h"
#include "../inc/constants.h"
#include "../inc/load_dynlib.h"

int main(const int argc, const char **argv)
{
    int rc;
    int args_number;
    int file_len = 0;
    char in_file_name[INPUT_FILE_NAME_SIZE];
    char out_file_name[OUTPUT_FILE_NAME_SIZE];
    char filtr[FILTR_SIZE];
    int *array = NULL;

    rc = load_library();
    if (rc != OK)
        return rc;

    if (parse_args(argc, argv, &args_number, in_file_name, out_file_name, filtr) != OK)
        return ARGS_ERROR;

    LOG_INFO("ARGS_NUMBER=%d", args_number);
    LOG_INFO("IN_FILE_NAME=%s", in_file_name);
    LOG_INFO("OUT_FILE_NAME=%s", out_file_name);

    FILE *f_in = fopen(in_file_name, "r");
    if (f_in == NULL)
        return FILE_OPEN_ERROR;

    if (fgetc(f_in) == EOF)
    {
        if (fclose(f_in) == EOF)
            return CLOSE_FILE_ERROR;

        return FILE_OPEN_ERROR;
    }
    rewind(f_in);

    scan_file_len(f_in, &file_len);

    array = (int *)malloc(file_len * sizeof(int));
    if (array == NULL)
    {
        if (fclose(f_in) == EOF)
            return CLOSE_FILE_ERROR;

        return MEMORY_ALLOCATION_ERROR;
    }

    fill_array(f_in, array);

    if (fclose(f_in) == EOF)
    {
        free(array);

        return CLOSE_FILE_ERROR;
    }

    FILE *f_out = fopen(out_file_name, "w");
    if (f_out == NULL)
    {
        free(array);

        return FILE_OPEN_ERROR;
    }

    mysort(array, file_len, sizeof(int), compare);

    if (args_number == ARGS_UPPER_LIMIT)
    {
        int test;
        int *pb_dst = NULL, *pe_dst = NULL;

        pb_dst = (int *)malloc(file_len * sizeof(int));
        if (pb_dst == NULL)
        {
            free(array);

            if (fclose(f_out) == EOF)
                return CLOSE_FILE_ERROR;
        }

        test = key(array, array + file_len, pb_dst, &pe_dst);

        free(array);

        if (test != OK)
        {
            free(pb_dst);

            if (fclose(f_out) == EOF)
                return CLOSE_FILE_ERROR;

            return test;
        }

        fill_file(f_out, pb_dst, pe_dst);

        free(pb_dst);

        if (fclose(f_out) == EOF)
            return CLOSE_FILE_ERROR;

        return OK;
    }

    fill_file(f_out, array, array + file_len);
    
    free(array);

    if (fclose(f_out) == EOF)
        return CLOSE_FILE_ERROR;

    return OK;
}
