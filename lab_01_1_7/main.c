#include <stdio.h>
#include <math.h>
 
#define OK 0
#define ERROR 1
 
double el_of_cert(double x, int n)
{
    return -1 * pow(x, 2) / ((n * 2) * (n * 2 + 1));
}
 
double sum_of_cert(double x, double eps, int n)
{
    double sn, sx;
    
    sn = x;
    sx = x;
    while (fabs(sn) > eps)
    {
        sn *= el_of_cert(x, n);
        sx += sn;
        n++;
    }
 
    return sx;
}

double absol_eps(double sx, double x)
{
    return fabs(sin(x) - sx);
}

double relative_eps(double sx, double x)
{
    return fabs((sin(x) - sx) / sin(x));
}
 
int main(void)
{
    double x, eps, sx;
    double abs_eps, relat_eps;
    int n = 1, check;
 
    printf("Введите значения переменной x и eps: ");
    check = scanf("%lf%lf", &x, &eps);
    if (check == 2 && eps > 0 && eps < 1)
    {
        sx = sum_of_cert(x, eps, n);
        abs_eps = absol_eps(sx, x);
        relat_eps = relative_eps(sx, x);
        printf("Приближенное значение функции s(x): ");
        printf("%.5f", sx);
        printf("\nТочное значение функции f(x): ");
        printf("%.5f", sin(x));
        printf("\nАбсолютная погрешность: %.5f", abs_eps);
        printf(" Относительная погрешность: %.5f\n", relat_eps);
 
        return OK;
    }
    printf("Исходные данные введены неправильно!");
   
    return ERROR;
}
