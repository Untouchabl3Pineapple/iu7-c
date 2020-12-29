#include <stdio.h>

#define ARRAY_SIZE 10
#define CORRECT_INPUT 1
#define LOWER_LIMIT 0
#define UPPER_LIMIT 10
#define OK 0
#define INPUT_ARRAY_ERROR 1
#define INPUT_LEN_ERROR 2
#define ARRAY_ERROR 3

int sequence_len(int *pa, int *const start, int *const end)
{
    int positive = 0, negative = 0;
    
    for (int *i = start; i != end; i++, pa++)
    {
        if (*pa > 0)
            positive++;
        else if (*pa < 0)
            negative++;
    }
    
    if (positive < negative)
        return positive;
    else
        return negative;
}

int sum_of_a_sequence(int *pa, int *const start, int *const end)
{
    int seq_len = sequence_len(pa, start, end);
    int summ = 0;
    int *p_second_el = end, counter = 0;
    
    for (int *i = start; i != end; i++, pa++)
    {
        if (counter == seq_len)
            break;
        
        if (*pa < 0)
        {
            while (*p_second_el <= 0)
                p_second_el--;
            
            summ += (*pa) * (*p_second_el);
            p_second_el--;
            counter++;
        }
    }
    
    if (summ == 0)
    {
        printf("Отсутствуют элементы удовлетворяющие условию!\n");
        
        return ARRAY_ERROR;
    }
    
    printf("Сумма последовательности = %d\n", summ);
    
    return summ;
}

int input_array(int *pa, int *const start, int *const end)
{
    int el_of_array;

    for (int *i = start; i != end; i++, pa++)
    {
        printf("Введите элемент массива: ");
        
        if (scanf("%d", &el_of_array) != 1)
        {
            printf("Введен неверный элемент массива!\n");
            
            return INPUT_ARRAY_ERROR;
        }
        
        *pa = el_of_array;
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
        int *pa = a, *start = a, *end = a + len_array;
        
        if (input_array(pa, start, end) == INPUT_ARRAY_ERROR)
            return INPUT_ARRAY_ERROR;
        
        if (sum_of_a_sequence(pa, start, end) == ARRAY_ERROR)
            return ARRAY_ERROR;
        
        return OK;
    }

    printf("Неверно указано количество элементов массива!\n");
        
    return INPUT_LEN_ERROR;
}
