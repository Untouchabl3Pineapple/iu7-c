#ifndef __PROCESS_LIB_H__

#define __PROCESS_LIB_H__

#include <stdio.h>

#include "macrologger.h"
#include "constants.h"

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

int compare(const void *x, const void *y);

void mysort(void *base, size_t nel, size_t width, int (*compar)(const void *, const void *));

int key(const int *pb_src, const int *pe_src, int *pb_dst, int **pe_dst);

#endif // __PROCESS_LIB_H__
