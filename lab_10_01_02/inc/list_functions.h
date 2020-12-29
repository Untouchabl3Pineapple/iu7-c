#ifndef __LIST_FUNCTIONS_H__

#define __LIST_FUNCTIONS_H__

#include <stdlib.h>
#include <stdio.h>

#include "macrologger.h"
#include "constants.h" 
#include "data_structures.h"
#include "stack_functions.h"
#include "memory_functions.h"

int decrease_degree_check(node_t *head);

int del_node_by_pointer(node_t *head, node_t *node);

int list_copy(node_t *head, node_t **head_copy);

node_t *find_var_degree(node_t *head, node_t *node);

int insert_node(node_t **head, node_t *node);

#endif // __LIST_FUNCTIONS_H__
