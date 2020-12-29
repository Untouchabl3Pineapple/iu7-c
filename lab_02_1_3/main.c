#include <stdio.h>

#define ARRAY_SIZE 20
#define CORRECT_INPUT 1
#define LOWER_LIMIT 0
#define UPPER_LIMIT 10
#define OK 0
#define INPUT_ARRAY_ERROR 1
#define INPUT_LEN_ERROR 2

void print_array(int *const a, int const len_array)
{
    printf("Cформированный массив: ");
    
    for (int i = 0; i != len_array; i++)
    {
        printf("%d ", a[i]);
    }
}

int fibonacci_number(int const counter_fib)
{
    // n - счетчик для достижения заданного числа фибоначчи
    int n = 0;
    int first_number = 0, second_number = 1;
    
    while (n != counter_fib)
    {
        int temp = first_number + second_number;
        first_number = second_number;
        second_number = temp;
        n++;
    }
    
    return first_number;
}

int *insert_fib_numbs_into_an_array(int *const a, int len_array)
{
    int counter_fib = 0;
    
    for (int i = 0; i != len_array; i++)
    {
        if (a[i] % 3 == 0)
        {
            len_array += 1;
            
            for (int j = len_array - 1; j != i + 1; j--)
            {
                a[j] = a[j - 1];
            }
            
            a[i + 1] = fibonacci_number(counter_fib);
            counter_fib++;
            i++;
        }
    }

    print_array(a, len_array);
        
    printf("\n");
        
    return a;
}

int input_array(int *const a, int const len_array)
{
    int el_of_array;

    for (int i = 0; i != len_array; i++)
    {
        printf("Введите элемент массива: ");
        
        if (scanf("%d", &el_of_array) != 1)
        {
            printf("Введен неверный элемент массива!\n");
            
            return INPUT_ARRAY_ERROR;
        }
        
        a[i] = el_of_array;
    }
    
    return OK;
}

int main(void)
{
    int len_array;
    
    int a[ARRAY_SIZE] = { 0 };
    
    printf("Введите количество элементов массива: ");
    
    if (scanf("%d", &len_array) == CORRECT_INPUT && len_array > \
        LOWER_LIMIT && len_array <= UPPER_LIMIT)
    {
        if (input_array(a, len_array) == INPUT_ARRAY_ERROR)
            return INPUT_ARRAY_ERROR;
        
        insert_fib_numbs_into_an_array(a, len_array);
        
        return OK;
    }
    
    printf("Неверно указано количество элементов массива!\n");
        
    return INPUT_LEN_ERROR;
}

