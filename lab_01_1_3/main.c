#include <stdio.h>

#define OK 0

int main(void)
{
    float v1, t1, v2, t2, v, t;

    printf("Объем первой жидкости: ");
    scanf("%f", &v1);
    printf("Температура первой жидкости: ");
    scanf("%f", &t1);
    printf("Объем второй жидкости: ");
    scanf("%f", &v2);
    printf("Температура второй жидкости: ");
    scanf("%f", &t2);
    v = v1 + v2;
    t = (v1 * t1 + v2 * t2) / v;
    printf("Объем = %.5f\nТемпература = %.5f", v, t);

    return OK;
}
