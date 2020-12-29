#include <stdio.h>

#define ARRAY_SIZE 10
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

int insertion_sort(int *const a, int const len_array)
{
    for (int i = 0; i != len_array; i++)
    {
        int j = i - 1;
        int buff = a[i];
        
        while (a[j] > buff && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = buff;
    }
    
    print_array(a, len_array);
    
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
        
        insertion_sort(a, len_array);
        
        return OK;
    }

    printf("Неверно указано количество элементов массива!\n");
        
    return INPUT_LEN_ERROR;
}


