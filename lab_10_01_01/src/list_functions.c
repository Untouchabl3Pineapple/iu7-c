#include "../inc/list_functions.h"

int push(node_t **head, void *data)
{
    if (head == NULL || data == NULL)
        return PUSH_DATA_ERROR;

    node_t *node = node_init(data);
    if (node == NULL)
        return MEMORY_ALLOCATION_ERROR;

    node->next = *head;
    *head = node;

    return OK;
}

void *pop_front(node_t **head)
{        
    if (head == NULL || *head == NULL)
        return NULL;

    void *data;
    node_t *head_p;

    data = (*head)->data;
    head_p = *head;
    *head = (*head)->next;

    free(head_p);

    return data;
}

void *pop_back(node_t **head)
{
    if (head == NULL || *head == NULL)
        return NULL;

    void *data;
    node_t *temp_head = *head, *temp_head_p;

    for (; temp_head->next && temp_head->next->next; temp_head = temp_head->next);

    if (temp_head->next != NULL) 
    {
        data = temp_head->next->data;
        temp_head_p = temp_head->next;
        temp_head->next = NULL;
    }
    else
    {
        data = temp_head->data;
        temp_head_p = temp_head;
        *head = NULL;
    }

    free(temp_head_p);
    
    return data;
}

node_t *reverse(node_t *head)
{
    node_t *head_reverse = NULL;

    for (; head;)
    {
        if (push(&head_reverse, pop_front(&head)) != OK)
            return NULL;
    }

    return head_reverse;
}

int del_numbs(node_t **head, const int number_del)
{
    if (head == NULL || *head == NULL)
        return UNDERFLOW_ERROR;

    for (int i = 0; i < number_del; i++)
    {
        if (pop_front(head) == NULL)
            return UNDERFLOW_ERROR;
        if (pop_back(head) == NULL)
            return UNDERFLOW_ERROR;
    }

    return OK;
}
