#include <stdio.h>

#define ARRAY_SIZE 10
#define CORRECT_INPUT 1
#define LOWER_LIMIT 0
#define UPPER_LIMIT 10
#define OK 0
#define INPUT_ARRAY_ERROR 1
#define INPUT_LEN_ERROR 2
#define ARRAY_ERROR 4

int the_product_of_the_odd_elem(int *const a, int const len_array)
{
    int res = 1;
    int counter = 0;
    
    for (int i = 0; i != len_array; i++)
    {
        if (a[i] % 2 != 0)
        {
            res *= a[i];
            counter++;
        }
    }
    
    if (counter == 0)
    {
        printf("В массиве нет нечетных элементов!\n");
        
        return ARRAY_ERROR;
    }
    
    printf("Произведение нечетных элементов массива = ");
    printf("%d\n", res);
        
    return res;
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
        
        if (the_product_of_the_odd_elem(a, len_array) == ARRAY_ERROR)
            return ARRAY_ERROR;
        
        return OK;
    }

    printf("Неверно указано количество элементов массива!\n");
            
    return INPUT_LEN_ERROR;
}
