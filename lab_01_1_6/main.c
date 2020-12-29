#include <stdio.h>
#include <math.h>

#define OK 0
#define ERROR 1
#define EPS 1e-7

double side_len(double f_x, double s_x, double f_y, double s_y)
{
    return sqrt(pow(s_x - f_x, 2) + pow(s_y - f_y, 2));
}

double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
    double len_fs, len_ss, len_ts;
    double p, s;
    
    len_fs = side_len(x1, x2, y1, y2);
    len_ss = side_len(x2, x3, y2, y3);
    len_ts = side_len(x3, x1, y3, y1);
    p = (len_fs + len_ss + len_ts) / 2;
    s = sqrt(p * (p - len_fs) * (p - len_ss) * (p - len_ts));
    
    return s;
}

int main(void)
{
    int check_f, check_s, check_t;
    double x1, y1, x2, y2, x3, y3;
    double s;

    printf("Введите координаты (x,y) первой вершины: ");
    check_f = scanf("%lf%lf", &x1, &y1);
    printf("Введите координаты (x,y) второй вершины: ");
    check_s = scanf("%lf%lf", &x2, &y2);
    printf("Введите координаты (x,y) третьей вершины: ");
    check_t = scanf("%lf%lf", &x3, &y3);
    if (check_f == 2 && check_s == 2 && check_t == 2)
    {
        s = area(x1, y1, x2, y2, x3, y3);
        if (s > EPS)
        {
            printf("Значение площади: ");
            printf("%.5f\n", s);

            return OK;
        }
        printf("Исходные данные введены неправильно!");

        return ERROR;
    }
    printf("Исходные данные введены неправильно!");

    return ERROR;
}
