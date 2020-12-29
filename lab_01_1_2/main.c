#include <stdio.h>
#include <math.h>

#define OK 0
#define DEGREES 180

int main(void)
{
    float a, b, s, h, alpha;
    float part;

    printf("Введите первое основание трапеции: ");
    scanf("%f", &a);
    printf("Введите второе основание трапеции: ");
    scanf("%f", &b);
    printf("Введите угол при большем основании трапеции (в градусах): ");
    scanf("%f", &alpha);
    part = fabs(a - b) / 2;
    h = tan(alpha * (M_PI / DEGREES)) * part;
    s = (a + b) / 2 * h;
    printf("Площадь трапеции равна %.5f\n", s);
    
    return OK;
}
