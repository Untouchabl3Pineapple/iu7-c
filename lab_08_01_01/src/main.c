#include "../inc/errors.h" 
#include "../inc/data_structures.h"
#include "../inc/io.h"
#include "../inc/matrix_convert.h"
#include "../inc/matrix_multiplication.h"

int main(void)
{
    matrix_t matrix_1, matrix_2, matrix_result;
    int exit_code;

    matrix_1.matrix = NULL;
    matrix_2.matrix = NULL;
    matrix_result.matrix = NULL;

    exit_code = matrix_fill(&matrix_1);
    if (exit_code != OK)
    {
        if (exit_code == MATRIX_FILL_ELEMENT_ERROR)
            free_matrix(&matrix_1, matrix_1.row);
        return exit_code;
    }

    exit_code = matrix_fill(&matrix_2);
    if (exit_code != OK)
    {
        free_matrix(&matrix_1, matrix_1.row);
        if (exit_code == MATRIX_FILL_ELEMENT_ERROR)
            free_matrix(&matrix_2, matrix_2.row);

        return exit_code;
    }

    exit_code = convert_to_square_matrix(&matrix_1);
    if (exit_code != OK)
    {
        free_matrix(&matrix_2, matrix_2.row);

        return exit_code;
    }

    exit_code = convert_to_square_matrix(&matrix_2);
    if (exit_code != OK)
    {
        free_matrix(&matrix_1, matrix_1.row);

        return exit_code;
    }

    exit_code = convert_matrices_single_size(&matrix_1, &matrix_2);
    if (exit_code != OK)
    {
        return exit_code;
    }

    exit_code = matrix_multiplication(&matrix_1, &matrix_2, &matrix_result);
    if (exit_code != OK)
    {
        free_matrix(&matrix_1, matrix_1.row);
        free_matrix(&matrix_2, matrix_2.row);
        if (exit_code != MEMORY_ALLOCATION_RES_ERROR)
            free_matrix(&matrix_result, matrix_result.row);

        return exit_code;
    }

    matrix_result_print(&matrix_result);

    free_matrix(&matrix_1, matrix_1.row);
    free_matrix(&matrix_2, matrix_2.row);
    free_matrix(&matrix_result, matrix_result.row);

    return OK;
}
