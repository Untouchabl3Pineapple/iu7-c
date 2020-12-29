#ifndef __PROCESS_LIB_H__

#define __PROCESS_LIB_H__

#include <math.h>

#include "data_structures.h"

void left_cyclic_shift(vector_t vector, const int kposc);

void parse_full_squares(vector_t vector, vector_t *parse_vector);

#endif // __PROCESS_LIB_H__
