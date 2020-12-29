#include "../inc/io_lib.h"

int fill_data(vector_t vector, FILE *f)
{
    for (int i = 0, rc, val; (rc = fscanf(f, "%d", &val) != EOF);)
    {
        if (rc != 1)
            return FILE_READING_ERROR;

        vector.vector[i++] = val;
    }

    return OK;
}

char *fill_filename(char *const filename)
{
    if (fscanf(stdin, "%s", filename) != 1)
        return NULL;

    return filename;
}

void print_vector(vector_t vector)
{
    for (int i = 0; i < vector.len; i++)
    {
        printf("%d ", vector.vector[i]);
    }

    printf("\n");
}
