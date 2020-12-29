#include "functions.h"

//parse_args(argc, char** argv, char* filename, char* ALL, char* filter ...)
int main(int argc, char **argv)
{
    int test;
    int items_len = 0;
    char filename[FILE_NAME_SIZE] = { '\0' };
    char filter[FILTER_SIZE] = { '\0' };
    description items_array[ARRAY_SIZE];

    if (parse_args(argc, argv, filename, filter) != OK)
        return ARGS_ERROR;

    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return FILE_READING_ERROR;
        
    if (feof(file))
    {
        if (fclose(file) == EOF)
            return FILE_CLOSE_ERROR;
        return FILE_READING_ERROR;
    }
    
    test = input_inform(items_array, &items_len, file);
    if (fclose(file) == EOF)
        return FILE_CLOSE_ERROR;
    if (test != OK)
        return test;
    if (argc == 2)
        insertion_sort(items_array, items_len);
        
    print_inform(items_array, items_len, argc, filter);
    
    return OK;
}
