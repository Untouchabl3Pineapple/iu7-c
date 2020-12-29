#include "../inc/constants.h" 
#include "../inc/data_structures.h"
#include "../inc/io.h"
#include "../inc/memory_functions.h" 
#include "../inc/stack_functions.h"
#include "../inc/list_functions.h"
#include "../inc/polynomial_functions.h"
#include "../inc/menu.h"

int main(void)
{
    int rc;
    char filter[FILTER_SIZE];
    node_t *head = NULL;

    if (filter_fill(filter) != OK)
        return FILTER_FILLING_ERROR;

    LOG_DEBUG("FILTER: %s", filter);
    
    rc = list_fill(&head);
    if (rc != OK)
        return rc;    
    if (reverse(&head) != OK)
        return MEMORY_ALLOCATION_ERROR;

    rc = menu(&head, filter);
    if (rc != OK)
        return rc;

    list_free(head);

    return OK;
}
