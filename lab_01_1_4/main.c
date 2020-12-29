#include <stdio.h>
#include <math.h>

#define OK 0
#define NUMB_OF_FLATS 36
#define FLATS_ON_THE_FLOOR 4

int main(void)
{
    int porch, floor, flat_numb;

    printf("Введите номер квартиры: ");
    scanf("%d", &flat_numb);
    porch = (flat_numb - 1) / NUMB_OF_FLATS + 1;
    floor = (flat_numb - 1 - (porch - 1) * NUMB_OF_FLATS) / FLATS_ON_THE_FLOOR + 1;
    printf("Номер подъезда = %d\nНомер этажа = %d\n", porch, floor);

    return OK;
}

