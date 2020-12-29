#include "../inc/stack_functions.h"

int push(node_t **head, const int coefficient, const int degree)
{
    node_t *node = node_init(coefficient, degree);
    if (node == NULL)
        return MEMORY_ALLOCATION_ERROR;

    node->next = *head;
    *head = node;

    return OK;
}

int del(node_t **head) 
{
    if (*head == NULL) 
        return STACK_UNDERFLOW;
        
    node_t *temp_node;

    temp_node = *head;
    *head = (*head)->next;
    free(temp_node);

    return OK;
}

int empty(node_t *head)
{
    if (head == NULL)
        return STACK_EMPTY;

    return OK;
}

int reverse(node_t **head)
{
    node_t *head_temp = NULL;

    for (; empty(*head) == OK; del(head))
    {
        if (push(&head_temp, (*head)->coefficient, (*head)->degree) != OK)
        {
            list_free(*head);
            list_free(head_temp);
            return MEMORY_ALLOCATION_ERROR;
        }
    }

    *head = head_temp;

    return OK;
}
