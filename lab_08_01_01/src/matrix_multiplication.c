#include "../inc/matrix_multiplication.h"

int multiplication(matrix_t *matrix, matrix_t *matrix_result)
{
    int *temp_row = (int*)malloc(matrix->row * sizeof(int));
    if (!temp_row)
    {
        free_matrix(matrix_result, matrix_result->row);
        return MEMORY_ALLOCATION_ERROR;
    }
    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0, sum; j < matrix->column; j++)
        {
            sum = 0;
            for (int k = 0; k < matrix->row; k++)
            {
                sum += matrix_result->matrix[i][k] * matrix->matrix[k][j];
            }
            temp_row[j] = sum;
        }
        for (int m = 0; m < matrix->row; m++)
        {
            matrix_result->matrix[i][m] = temp_row[m];
        }
    }
    free(temp_row);

    return OK;
}

int matrix_multiplication(matrix_t *matrix_1, matrix_t *matrix_2, matrix_t *matrix_result)
{
    matrix_result->row = matrix_1->row;
    matrix_result->column = matrix_1->column;

    LOG_DEBUG("MATRIX_RES_ROW=%d", matrix_result->row);
    LOG_DEBUG("MATRIX_RES_COLUMN=%d", matrix_result->column);

    if (allocate_matrix(matrix_result) != OK)
        return MEMORY_ALLOCATION_RES_ERROR;

    if (fscanf(stdin, "%d", &matrix_1->degree) != 1)
        return DEGREE_ERROR;
    if (matrix_1->degree < 0)
        return DEGREE_ERROR;
    if (fscanf(stdin, "%d", &matrix_2->degree) != 1)
        return DEGREE_ERROR;
    if (matrix_2->degree < 0)
        return DEGREE_ERROR; 

    LOG_DEBUG("MATRIX_1_DEGREE=%d", matrix_1->degree);
    LOG_DEBUG("MATRIX_2_DEGREE=%d", matrix_2->degree);

    convert_to_single_matrix(matrix_result);

    for (int i = 0; i < matrix_1->degree; i++)
    {
        if (multiplication(matrix_1, matrix_result) != OK)
            return MEMORY_ALLOCATION_ERROR;
    }
    for (int i = 0; i < matrix_2->degree; i++)
    {
        if (multiplication(matrix_2, matrix_result) != OK)
            return MEMORY_ALLOCATION_ERROR;
    }

    return OK;
}
