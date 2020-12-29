#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define CORRECT_INPUT 1
#define MATRIX_ROW_ERROR 1
#define MATRIX_COLUMN_ERROR 2
#define MATRIX_ELEMENT_ERROR 3
#define LOWER_LIMIT 1
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

void print_matrix(int const mr, int const mc, int (*m)[COLUMN], \
int const first_ind, int const second_ind)
{
    int flag;
    
    for (int i = 0; i < mr; i++)
    {
        flag = 0;
        for (int j = 0; j < mc; j++)
        {
            if (i == first_ind)
                break;
            if (j == second_ind)
                continue;
            else
            {
                printf("%d ", m[i][j]);
                flag = 1;
            }
        }
        if (flag == 1)
            printf("\n");
    }
}

int sum_of_digits(int number)
{
    int sum = 0;
    
    number = abs(number);
    while (number / 10 != 0)
    {
        sum += number % 10;
        number /= 10;
    }
    
    return sum += number % 10;
}

void find_min_numb_in_matrix(int const mr, int const mc, int (*m)[COLUMN], \
int *const first_ind, int *const second_ind)
{
    int min = m[0][0];
    
    for (int i = 0; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            int sum = sum_of_digits(m[i][j]);
        
            if (sum < min)
            {
                min = sum;
                *first_ind = i;
                *second_ind = j;
            }
        }
    }
}

void transform_matrix(int const mr, int const mc, int (*m)[COLUMN])
{
    /*
     first_ind - row number
     second_ind - column number
     */
    int first_ind = 0, second_ind = 0;
    
    find_min_numb_in_matrix(mr, mc, m, &first_ind, &second_ind);
    print_matrix(mr, mc, m, first_ind, second_ind);
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
