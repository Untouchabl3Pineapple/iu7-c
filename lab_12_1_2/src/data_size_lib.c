#include "../inc/data_size_lib.h"

int get_data_size(FILE *f)
{
    int size = 0;

    for (int rc, val; (rc = fscanf(f, "%d", &val) != EOF); size++)
    {
        if (rc != 1)
            return FILE_READING_ERROR;
    }

    return size;
}
