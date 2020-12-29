#ifndef __STACK_FUNCTIONS_H__

#define __STACK_FUNCTIONS_H__

#include <stdlib.h>

#include "constants.h" 
#include "data_structures.h"
#include "memory_functions.h"

int push(node_t **head, const int coefficient, const int degree);

int del(node_t **head);

int empty(node_t *head);

int reverse(node_t **head);

#endif // __STACK_FUNCTIONS_H__
