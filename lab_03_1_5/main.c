#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define CORRECT_INPUT 1
#define MATRIX_ROW_ERROR 1
#define MATRIX_COLUMN_ERROR 2
#define MATRIX_ELEMENT_ERROR 3
#define SUM_OF_DIGITS_ERROR 4
#define LOWER_LIMIT 0
#define UPPER_LIMIT 10
#define ROW 10
#define COLUMN 10
#define ARRAY_SIZE 100

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

int condition_test(int *const mr, int *const mc, int (*m)[COLUMN])
{
    printf("input the number of rows in the matrix: ");
    if (scanf("%d", mr) != CORRECT_INPUT || *mr <= LOWER_LIMIT || *mr > UPPER_LIMIT)
        return MATRIX_ROW_ERROR;
   
    printf("input the number of columns in the matrix: ");
    if (scanf("%d", mc) != CORRECT_INPUT || *mc <= LOWER_LIMIT || *mc > UPPER_LIMIT)
        return MATRIX_COLUMN_ERROR;
   
    int flag = 0;
    for (int i = 0; i < *mr; i++)
    {
        for (int j = 0; j < *mc; j++)
        {
            printf("input the matrix element: ");
            if (scanf("%d", &m[i][j]) != CORRECT_INPUT)
                return MATRIX_ELEMENT_ERROR;
            if (sum_of_digits(m[i][j]) > 10)
                flag = 1;
        }
    }
    if (flag == 0)
        return SUM_OF_DIGITS_ERROR;
   
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

void cyclic_shift(int *const a, int const len_a)
{
    for (int i = 0; i < 3; i++)
    {
        int temp = a[0];
        
        for (int j = 0; j < len_a - 1; j++)
        {
            a[j] = a[j + 1];
        }
        
        a[len_a - 1] = temp;
    }
}

void form_array(int const mr, int const mc, \
int (*m)[COLUMN], int *ind, int *const a)
{
    for (int i = 0; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            if (sum_of_digits(m[i][j]) > 10)
            {
                a[*ind] = m[i][j];
                (*ind)++;
            }
        }
    }
    
    cyclic_shift(a, *ind);
}

void transform_matrix(int const mr, int const mc, int (*m)[COLUMN])
{
    int ind_counter = 0;
    int len_array = 0;
    int a[ARRAY_SIZE] = { 0 };
    
    form_array(mr, mc, m, &len_array, a);
    
    for (int i = 0; i < mr; i++)
    {
        for (int j = 0; j < mc; j++)
        {
            if (sum_of_digits(m[i][j]) > 10)
            {
                m[i][j] = a[ind_counter];
                ind_counter++;
            }
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
