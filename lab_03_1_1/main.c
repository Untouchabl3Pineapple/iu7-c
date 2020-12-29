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
#define ARRAY_SIZE 10
#define TRUE 0
#define FALSE 1

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

void print_array(int *const a, int const len_array)
{
    for (int i = 0; i < len_array; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int is_symmetry(int const mc, int (*m)[COLUMN], int const k)
{
    int first_ind = 0, second_ind = mc - 1;
    
    while (first_ind < second_ind)
    {
        if (m[k][first_ind] != m[k][second_ind])
            return FALSE;
        
        if (mc % 2 == 1 && first_ind == second_ind)
            break;
        if (mc % 2 == 0 && first_ind == second_ind - 1)
            break;
        
        first_ind++;
        second_ind--;
    }
    
    return TRUE;
}

int form_array(int const mr, int const mc, int (*m)[COLUMN])
{
    int a[ARRAY_SIZE] = { 0 };
    
    for (int i = 0; i < mr; i++)
    {
        if (is_symmetry(mc, m, i) == TRUE)
            a[i] = 1;
        else
            a[i] = 0;
    }
    
    print_array(a, mr);
    
    return 0;
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
    
    form_array(mr, mc, m);
    
    return OK;
}
