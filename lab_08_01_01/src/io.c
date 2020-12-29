#include "../inc/io.h"

int matrix_fill(matrix_t *matrix)
{
    if (fscanf(stdin, "%d", &matrix->row) != 1)
        return MATRIX_FILL_PARAMETR_ERROR;
    if (matrix->row < 1)
        return MATRIX_FILL_PARAMETR_ERROR;
    if (fscanf(stdin, "%d", &matrix->column) != 1)
        return MATRIX_FILL_PARAMETR_ERROR;
    if (matrix->column < 1)
        return MATRIX_FILL_PARAMETR_ERROR;

    if (allocate_matrix(matrix) != OK)
        return MEMORY_ALLOCATION_ERROR;

    LOG_INFO("ROW=%d COLUMN=%d", matrix->row, matrix->column);

    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->column; j++)
        {
            if (fscanf(stdin, "%d", &matrix->matrix[i][j]) != 1)
                return MATRIX_FILL_ELEMENT_ERROR;
        }
    }

    return OK;
}

void matrix_result_print(matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->column; j++)
        {
            printf("%20d ", matrix->matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
