#include <stdio.h>

#define OK 0
#define CORRECT_INPUT 1
#define MATRIX_ROW_ERROR 1
#define MATRIX_COLUMN_ERROR 2
#define MATRIX_ELEMENT_ERROR 3
#define NOT_SQUARE_ERROR 4
#define LOWER_LIMIT 0
#define UPPER_LIMIT 10
#define ROW 10
#define COLUMN 10

int condition_test(int *const mr, int *const mc, int (*m)[COLUMN])
{
    printf("input the number of rows in the matrix: ");
    if (scanf("%d", mr) != CORRECT_INPUT || *mr <= LOWER_LIMIT || *mr > UPPER_LIMIT)
        return MATRIX_ROW_ERROR;
   
    printf("input the number of columns in the matrix: ");
    if (scanf("%d", mc) != CORRECT_INPUT || *mc <= LOWER_LIMIT || *mc > UPPER_LIMIT)
        return MATRIX_COLUMN_ERROR;
    
    if (*mr != *mc)
        return NOT_SQUARE_ERROR;
   
    for (int i = 0; i < *mr; i++)
    {
        for (int j = 0; j < *mc; j++)
        {
            printf("input the matrix element: ");
            if (scanf("%d", &m[i][j]) != CORRECT_INPUT)
                return MATRIX_ELEMENT_ERROR;
        }
    }
   
    return OK;
}

void print_matrix(int const mr, int const mc, int (*m)[COLUMN])
{
    for (int i = 0; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            printf("%-4d", m[i][j]);
        }
        printf("\n");
    }
}

void transform_matrix(int const mr, int const mc, int (*m)[COLUMN])
{
    /*
    first_ind - row number
    second_ind - column number
    */
    int first_ind = 0, second_ind = mc - 1;
    int temp;
    
    for (int i = 0; i < mr / 2 + mr % 2; i++, first_ind++, second_ind--)
    {
        for (int j = first_ind; j < second_ind + 1; j++)
        {
            temp = m[i][j];
            m[i][j] = m[second_ind][j];
            m[second_ind][j] = temp;
        }
    }
    
    print_matrix(mr, mc, m);
}

/*
 m - matrix
 mr - matrix_row
 mc - matrix_column
 */

int main(void)
{
    int mr, mc;
    int m[ROW][COLUMN] = { 0 };
    int test;
   
    test = condition_test(&mr, &mc, m);
    if (test != OK)
        return test;
    
    transform_matrix(mr, mc, m);
    
    return OK;
}
