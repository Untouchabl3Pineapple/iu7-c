#include "../inc/matrix_allocate_and_free.h"

int allocate_matrix(matrix_t *matrix)
{
    matrix->matrix = (int**)calloc(matrix->row, sizeof(int*));
    if (!matrix->matrix)
        return MEMORY_ALLOCATION_ERROR;

    for (int i = 0; i < matrix->row; i++)
    {
        matrix->matrix[i] = (int*)calloc(matrix->column, sizeof(int));
        if (!matrix->matrix[i])
        {
            free_matrix(matrix, matrix->row);
            return MEMORY_ALLOCATION_ERROR;
        }
    }

    return OK;
}

int reallocate_matrix(matrix_t *smaller_matrix, matrix_t *large_matrix)
{
    int **pdata, *pdata_row;

    pdata = (int**)realloc(smaller_matrix->matrix, large_matrix->row * sizeof(int*));
    if (!pdata)
    {
        free_matrix(smaller_matrix, smaller_matrix->row);
        free_matrix(large_matrix, large_matrix->row);
        return MEMORY_ALLOCATION_ERROR;
    }
    smaller_matrix->matrix = pdata;
    
    for (int i = 0; i < smaller_matrix->row; i++)
    {
        pdata_row = (int*)realloc(smaller_matrix->matrix[i], \
        large_matrix->column * sizeof(int));
        if (!pdata_row)
        {
            free_matrix(smaller_matrix, i);
            free_matrix(large_matrix, large_matrix->row);
            return MEMORY_ALLOCATION_ERROR;
        }
        smaller_matrix->matrix[i] = pdata_row;
    }

    for (int i = smaller_matrix->row; i < large_matrix->row; i++)
    {
        smaller_matrix->matrix[i] = (int*)malloc(large_matrix->column * sizeof(int));
        if (!smaller_matrix->matrix[i])
        {
            free_matrix(smaller_matrix, i);
            free_matrix(large_matrix, large_matrix->row);
            return MEMORY_ALLOCATION_ERROR;
        }
    }

    return OK;
}

void free_matrix(matrix_t *matrix, int index)
{
    for (int i = 0; i < index; i++)
    {
        free(matrix->matrix[i]);
    }
    free(matrix->matrix);
}
