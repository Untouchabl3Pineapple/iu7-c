#include "../inc/macrologger.h"
#include "../inc/data_structures.h"
#include "../inc/errors.h"
#include "../inc/io.h"
#include "../inc/sort.h"
#include "../inc/data_memory_functions.h"

int main(const int argc, char **const argv)
{
    int rc;
    int args_number;
    char filename[FILE_NAME_SIZE] = { '\0' };
    char filter[FILTER_SIZE] = { '\0' };
    int items_len = 0;
    item_t *items_array;

    if (parse_args(argc, argv, &args_number, filename, filter) != OK)
        return ARGS_ERROR;

    FILE *file = fopen(filename, "r");
    if (file == NULL)
        return FILE_READING_ERROR;

    rc = is_empty(file);
    if (rc != OK)
        return rc;

    if (array_allocate(&items_array, &items_len, file) != OK)
    {
        if (fclose(file) == EOF)
            return FILE_CLOSE_ERROR;
        return ALLOCATION_ERROR;
    }

    int test = input_inform(items_array, items_len, file);

    if (fclose(file) == EOF)
        return FILE_CLOSE_ERROR;

    if (test != OK)
        return test;

    if (args_number == 2)
        insertion_sort(items_array, items_len);
        
    print_inform(items_array, items_len, args_number, filter);
    data_free(&items_array, items_len);

    return OK;
}
