#include "../inc/matrix_convert.h"

void find_max_digit_in_matrix(matrix_t *matrix, int *const row_ind, int *const column_ind)
{
    int max = matrix->matrix[0][0];

    *row_ind = 0;
    *column_ind = 0; 

    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = 0; j < matrix->column; j++)
        {
            if (matrix->matrix[i][j] > max)
            {
                max = matrix->matrix[i][j];
                *row_ind = i;
                *column_ind = j;  
            }
        }
    }
}

int delete_matrix_row(matrix_t *matrix, const int row_ind)
{
    int **pdata;

    free(matrix->matrix[row_ind]);
    for (int i = row_ind; i < matrix->row - 1; i++)
    {
        matrix->matrix[i] = matrix->matrix[i + 1];
    }

    pdata = (int**)realloc(matrix->matrix, (matrix->row - 1) * sizeof(int*));
    if (!pdata)
    {
        free_matrix(matrix, matrix->row);
        return MEMORY_ALLOCATION_ERROR;
    }
    matrix->matrix = pdata;

    matrix->row--;

    return OK;
}

int delete_matrix_column(matrix_t *matrix, const int column_ind)
{
    int *pdata_row;

    for (int i = 0; i < matrix->row; i++)
    {
        for (int j = column_ind; j < matrix->column - 1; j++)
        {
            matrix->matrix[i][j] = matrix->matrix[i][j + 1];
        }

        pdata_row = (int*)realloc(matrix->matrix[i], \
        (matrix->column - 1) * sizeof(int));
        if (!pdata_row)
        {
            free_matrix(matrix, matrix->row);
            return MEMORY_ALLOCATION_ERROR;
        }
        matrix->matrix[i] = pdata_row;
    }
    
    matrix->column--;

    return OK;
}

int convert_to_square_matrix(matrix_t *matrix)
{
    int row_ind = 0, column_ind = 0;

    if (matrix->row > matrix->column)
    {
        for (; matrix->row > matrix->column;)
        {
            find_max_digit_in_matrix(matrix, &row_ind, &column_ind);
            LOG_DEBUG("ROW_INDEX=%d", row_ind);
            if (delete_matrix_row(matrix, row_ind) != OK)
                return MEMORY_ALLOCATION_ERROR;
        }
    }
    else if (matrix->row < matrix->column)
    {
        for (; matrix->column > matrix->row;)
        {
            find_max_digit_in_matrix(matrix, &row_ind, &column_ind);
            LOG_DEBUG("COLUMN_INDEX=%d", column_ind);
            if (delete_matrix_column(matrix, column_ind) != OK)
                return MEMORY_ALLOCATION_ERROR;
        }
    }   

    return OK;
}

int find_max_element_in_array(int *const array, const int array_len)
{
    int max = array[0];

    for (int i = 0; i < array_len; i++)
    {
         if (array[i] > max)
            max = array[i];
    }

    return max;
}

void fill_new_matrix_rows(matrix_t *smaller_matrix, matrix_t *large_matrix)
{
    float sum;

    for (int i = 0; i < smaller_matrix->column; i++)
    {
        sum = 0.0;
        for (int j = 0; j < large_matrix->row; j++)
        {
            if (smaller_matrix->row < j + 1)
                smaller_matrix->matrix[j][i] = floor(sum / j);
            sum += smaller_matrix->matrix[j][i]; 
        }
    }

    smaller_matrix->row = large_matrix->row ;
}

void fill_new_matrix_columns(matrix_t *smaller_matrix, matrix_t *large_matrix)
{
    for (int i = smaller_matrix->column; i < large_matrix->column; i++)
    {
        for (int j = 0; j < smaller_matrix->row; j++)
        {
            smaller_matrix->matrix[j][i] = find_max_element_in_array(smaller_matrix->matrix[j], \
            smaller_matrix->column);
        }
    }

    smaller_matrix->column = large_matrix->column;
}

int convert_matrices_single_size(matrix_t *matrix_1, matrix_t *matrix_2)
{
    if (matrix_1->row < matrix_2->row)
    {
        if (reallocate_matrix(matrix_1, matrix_2) != OK)
            return MEMORY_ALLOCATION_ERROR;
        fill_new_matrix_rows(matrix_1, matrix_2);
        fill_new_matrix_columns(matrix_1, matrix_2);
    }
    else if (matrix_1->row > matrix_2->row)
    {
        if (reallocate_matrix(matrix_2, matrix_1) != OK)
            return MEMORY_ALLOCATION_ERROR;
        fill_new_matrix_rows(matrix_2, matrix_1);
        fill_new_matrix_columns(matrix_2, matrix_1);
    }

    return OK;
}

void convert_to_single_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix->row; i++)
    {
        matrix->matrix[i][i] = 1;
    }
}
