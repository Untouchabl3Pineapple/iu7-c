#ifndef __MENU_H__

#define __MENU_H__

#include <string.h>

#include "constants.h" 
#include "data_structures.h"
#include "io.h"
#include "memory_functions.h"
#include "stack_functions.h"
#include "list_functions.h"
#include "polynomial_functions.h"

int menu(node_t **head, const char *const filter);

#endif // __MENU_H__
