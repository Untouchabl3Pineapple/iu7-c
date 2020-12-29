#include <stdio.h>
#include <math.h>

#define ARRAY_SIZE 10
#define CORRECT_INPUT 1
#define LOWER_LIMIT 0
#define UPPER_LIMIT 10
#define PRIME_NUMBER 1
#define NOT_A_PRIME_NUMBER 0
#define OK 0
#define INPUT_ARRAY_ERROR 1
#define INPUT_LEN_ERROR 2
#define ARRAY_ERROR 3

void print_array(int *const a, int const len_array)
{
    printf("Cформированный массив: ");
    
    for (int i = 0; i != len_array; i++)
    {
        printf("%d ", a[i]);
    }
}

int checking_for_a_prime_number(int const number)
{
    if (number < 2)
        return NOT_A_PRIME_NUMBER;
    
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number % i == 0)
            return NOT_A_PRIME_NUMBER;
    }
    
    return PRIME_NUMBER;
}

int creating_a_new_array(int *const a, int const len_array)
{
    int counter = 0;
    
    int new_a[ARRAY_SIZE] = { 0 };
    
    for (int i = 0; i != len_array; i++)
    {
        if (checking_for_a_prime_number(a[i]) == PRIME_NUMBER)
        {
            new_a[counter] = a[i];
            counter++;
        }
    }
    
    if (counter == 0)
    {
        printf("В массиве нет простых чисел!\n");
        
        return ARRAY_ERROR;
    }
 
    print_array(new_a, counter);
        
    printf("\n");
        
    return OK;
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
 
        if (creating_a_new_array(a, len_array) == ARRAY_ERROR)
            return ARRAY_ERROR;
        
        return OK;
    }

    printf("Неверно указано количество элементов массива!\n");
        
    return INPUT_LEN_ERROR;
}

