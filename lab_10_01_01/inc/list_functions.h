#ifndef __LIST_FUNCTIONS_H__

#define __LIST_FUNCTIONS_H__

#include "constants.h" 
#include "data_structures.h"
#include "memory_functions.h"

int push(node_t **head, void *data);

void *pop_front(node_t **head);

void *pop_back(node_t **head);

node_t *reverse(node_t *head);

int del_numbs(node_t **head, const int number_del);

#endif // __LIST_FUNCTIONS_H__
