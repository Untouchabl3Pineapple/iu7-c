#include "../inc/memory_functions.h"

node_t *node_init(const int coefficient, const int degree)
{   
    node_t *node = (node_t *)malloc(sizeof(struct node_t));

    if (node)
    {
        node->coefficient = coefficient;
        node->degree = degree; 
        node->next = NULL;
    }

    return node;
}

void list_free(node_t *head)
{
    for (node_t *next; head; head = next)
    {
        next = head->next;
        free(head);
    }
}
