#include "../inc/menu.h"

int menu(node_t **head, const char *const filter)
{
    int rc;

    if (strcmp(filter, "val") == 0)
    {
        int var;
        
        if (fscanf(stdin, "%d", &var) != 1)
        {
            list_free(*head);
            return VAR_ERROR;
        }

        printf("%d", polynomial_value(*head, var));
    }
    else if (strcmp(filter, "ddx") == 0)  
    {
        node_t *tail = polynomial_derivative(*head);

        if (tail != NULL)
            del_node_by_pointer(*head, tail);

        list_print(*head);
    }
    else if (strcmp(filter, "sum") == 0)  
    {
        node_t *head_1 = NULL, *head_sum = NULL;

        rc = list_fill(&head_1);
        if (rc != OK)
        {
            list_free(*head);
            return rc;
        }    
        if (reverse(&head_1) != OK)
        {
            list_free(*head);
            return MEMORY_ALLOCATION_ERROR;
        }

        if (polynomial_sum(*head, head_1, &head_sum) != OK)
            return MEMORY_ALLOCATION_ERROR;

        list_print(head_sum);

        list_free(head_1);
        list_free(head_sum);
    }
    else if (strcmp(filter, "dvd") == 0)  
    {
        node_t *head_even = NULL, *head_odd = NULL;

        if (polynomial_degree_separation(*head, &head_even, &head_odd) != OK)
            return MEMORY_ALLOCATION_ERROR;
        
        list_print(head_even);
        list_print(head_odd);

        list_free(head_even);
        list_free(head_odd);
    }   

    return OK; 
}
