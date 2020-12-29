#include <stdio.h>
#include <math.h>

#define OK 0
#define ERROR 1

int find_quot(int a, int d)
{
    int quot = a * pow(d, -1);
    printf("Частное: %d ", quot);
    
    return quot;
}

int find_remaind(int a, int d)
{
    int r = 0;
    
    if (a < d)
        r = a;
    else
    {
        while (a >= d)
        {
            a -= d;
            r = a;
        }
    }
    printf("Остаток: %d\n", r);
    
    return r;
}

int main(void)
{
    int a, d;
    int check_inp;

    printf("Введите значение переменной a и d: ");
    check_inp = scanf("%d%d", &a, &d);
    if (check_inp == 2 && a >= 1 && d > 0)
    {
        find_quot(a, d);
        find_remaind(a, d);

        return OK;
    }
    printf("Исходные данные введены неправильно!");

    return ERROR;
}
