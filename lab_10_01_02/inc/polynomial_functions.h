#ifndef __POLYNOMIAL_FUNCTIONS_H__

#define __POLYNOMIAL_FUNCTIONS_H__

#include <stdio.h>
#include <math.h>

#include "macrologger.h"
#include "constants.h" 
#include "data_structures.h"
#include "stack_functions.h"
#include "list_functions.h"

int polynomial_value(node_t *head, const int var);

node_t *polynomial_derivative(node_t *head);

int polynomial_sum(node_t *head, node_t *head_1, node_t **head_sum);

int polynomial_degree_separation(node_t *head, node_t **head_even, node_t **head_odd);

#endif // __POLYNOMIAL_FUNCTIONS_H__
