#include "../inc/memory_lib.h"

int *vector_alloc(int *vector, const int len)
{
    vector = (int *) malloc(len * sizeof(int));

    if (vector == NULL)
        return NULL;

    return vector;
}

void vector_free(int *vector)
{
    free(vector);
}
