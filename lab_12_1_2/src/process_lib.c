#include "../inc/process_lib.h"

void left_cyclic_shift(vector_t vector, const int kposc)
{
    for (int i = 0, buf; i < kposc; i++)
    {
        buf = vector.vector[0];

        for (int j = 1; j < vector.len; j++)
        {
            vector.vector[j - 1] = vector.vector[j];
        }
        
        vector.vector[vector.len - 1] = buf;
    }
}

void parse_full_squares(vector_t vector, vector_t *parse_vector)
{
    double sqrt_res;

    parse_vector->len = 0;
    
    for (int i = 0, j = 0; i < vector.len; i++)
    {
        sqrt_res = sqrt(vector.vector[i]);
        
        if (fmod(sqrt_res, 1) == 0)
        {
            parse_vector->vector[j++] = vector.vector[i];
            parse_vector->len++;
        }
    }
}
