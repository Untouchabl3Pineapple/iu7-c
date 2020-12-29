#include "../inc/io.h"
#include "../inc/mysort_and_filtr.h"

int main(const int argc, const char **argv)
{
    int args_number;
    int file_len = 0;
    char in_file_name[INPUT_FILE_NAME_SIZE];
    char out_file_name[OUTPUT_FILE_NAME_SIZE];
    char filtr[FILTR_SIZE];
    int *array;

    if (parse_args(argc, argv, &args_number, in_file_name, out_file_name, filtr) != OK)
        return ARGS_ERROR;

    LOG_INFO("ARGS_NUMBER=%d", args_number);
    LOG_INFO("in_file_name=%s", in_file_name);
    LOG_INFO("out_file_name=%s", out_file_name);

    FILE *f_in = fopen(in_file_name, "r");
    if (f_in == NULL || fgetc(f_in) == EOF)
    {
        return FILE_OPEN_ERROR;
    }
    rewind(f_in);

    scan_file_len(f_in, &file_len);
    array = malloc(file_len * sizeof(int));
    if (!array)
    {
        if (fclose(f_in) == EOF)
            return CLOSE_FILE_ERROR;
        return MEMORY_ALLOCATION_ERROR;
    }
    rewind(f_in);

    fill_array(f_in, array);
    if (fclose(f_in) == EOF)
        return CLOSE_FILE_ERROR;

    FILE *f_out = fopen(out_file_name, "w");
    if (f_out == NULL)
    {
        if (array)
        {
            free(array);
        }
        return FILE_OPEN_ERROR;
    }

    if (args_number == ARGS_UPPER_LIMIT)
    {
        int test;
        int *pb_dst = NULL, *pe_dst = NULL;

        test = key(array, array + file_len, &pb_dst, &pe_dst);
        if (array)
        {
            free(array);
        }
        if (test != OK)
        {
            if (test == EMPTY_FILTR_ARRAY)
            {
                if (pb_dst)
                {
                    free(pb_dst);
                }
            }
            if (fclose(f_out) == EOF)
                return CLOSE_FILE_ERROR;
            return test;
        }

        mysort(pb_dst, pe_dst - pb_dst, sizeof(int), compare);
        fill_file(f_out, pb_dst, pe_dst);
        //print_array(pb_dst, pe_dst);

        if (pb_dst)
        {
            free(pb_dst);
        }
        if (fclose(f_out) == EOF)
            return CLOSE_FILE_ERROR;

        return OK;
    }

    mysort(array, file_len, sizeof(int), compare);
    fill_file(f_out, array, array + file_len);
    //print_array(array, array + file_len);
    
    if (array)
    {
        free(array);
    }
    if (fclose(f_out) == EOF)
        return CLOSE_FILE_ERROR;

    return OK;
}
