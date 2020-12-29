#ifndef __MEMORY_FUNCTIONS_H__

#define __MEMORY_FUNCTIONS_H__

#include <stdlib.h>

#include "data_structures.h"

node_t *node_init(void *data);

void list_free(node_t *head);

#endif // __MEMORY_FUNCTIONS_H__
