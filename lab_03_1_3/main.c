#include <stdio.h>

#define OK 0
#define CORRECT_INPUT 1
#define MATRIX_ROW_ERROR 1
#define MATRIX_COLUMN_ERROR 2
#define MATRIX_ELEMENT_ERROR 3
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
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void find_max_numb_in_matrix(int const mr, int const mc, int (*m)[COLUMN], \
int *const first_ind, int const counter_rows)
{
    int max = m[counter_rows][0];
    int flag = 0;
    
    for (int i = counter_rows; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            if (m[i][j] > max)
            {
                flag = 1;
                max = m[i][j];
                *first_ind = i;
            }
        }
    }
    
    if (flag == 0)
        *first_ind = counter_rows;
}

void transform_matrix(int const mr, int const mc, int (*m)[COLUMN])
{
    // first_ind - row number
    int first_ind, counter_rows = 0;
    int temp;
    
    for (int i = 0; i < mr; i++, counter_rows++)
    {
        find_max_numb_in_matrix(mr, mc, m, &first_ind, counter_rows);
        for (int j = 0; j < mc; j++)
        {
            temp = m[i][j];
            m[i][j] = m[first_ind][j];
            m[first_ind][j] = temp;
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
