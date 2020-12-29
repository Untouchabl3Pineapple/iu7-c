#include "../inc/mysort_and_filtr.h"

#define SWAP(a, b, size)                        \
	do                                          \
	{                                           \
	    size_t __size = (size);                 \
	    char *__a = (a), *__b = (b);            \
	    do                                      \
	    {                                       \
	        char __tmp = *__a;                  \
	        *__a++ = *__b;                      \
	        *__b++ = __tmp;                     \
	    } while (--__size > 0);                 \
	} while (0)

int compare(const void *x, const void *y)
{
    return (*(int *)x - *(int *)y);
}                         

void mysort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *))
{
    char  *copy_base = (char *)base;
    char  *pi, *pj;
    char  *p_max, *p_last;
    size_t i;

    for (pi = copy_base, i = 0; pi - copy_base < nel * width; pi += width, i++)
    {
        p_max = copy_base;
        for (pj = copy_base; pj - copy_base < nel * width - width * i; pj += width)
        {
            if (compar(pj, p_max) > 0)
            {
                p_max = pj;
            }
        }
        p_last = copy_base + nel * width - width * i - width;
        SWAP(p_last, p_max, width);
    }
}

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    const int *p_min, *p_max;
    const int *first_p_el, *last_p_el;

    if (pb_src == NULL || pe_src == NULL || pe_src - pb_src < 3)
        return EMPTY_SRC_ARRAY_ERROR;
    if (pe_src - pb_src < 3)
        return NO_ELEMENTS_BETWEEN_ERROR;

    for (p_min = pb_src, p_max = pb_src; pb_src < pe_src; pb_src++)
    {
        if (*pb_src < *p_min)
            p_min = pb_src;
        if (*pb_src > *p_max)
            p_max = pb_src;
    }

    if (p_min - p_max < 0)
    {
        first_p_el = p_min;
        last_p_el = p_max;
    }
    else
    {
        first_p_el = p_max;
        last_p_el = p_min;
    }
    if (last_p_el - first_p_el < 2)
        return NO_ELEMENTS_BETWEEN_ERROR;

    *pb_dst = malloc((last_p_el - first_p_el) * sizeof(int));
    if (!*pb_dst)
        return MEMORY_ALLOCATION_ERROR;
    *pe_dst = *pb_dst;
    
    for (; ++first_p_el < last_p_el; (*pe_dst)++)
    {
        **pe_dst = *first_p_el;
    }

    if (*pe_dst - *pb_dst == 0)
        return EMPTY_FILTR_ARRAY;

    return OK;
}
