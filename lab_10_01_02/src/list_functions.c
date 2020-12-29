#include "../inc/list_functions.h"

int decrease_degree_check(node_t *head)
{
    node_t *temp_head;

    /*
                CORRECT FORM:

        List --> 4,3 --> 2,2 --> 6,0 -->∅
    */

    for (; head; head = head->next)
    {
        for (temp_head = head->next; temp_head; temp_head = temp_head->next)
        {
            if (head->degree >= temp_head->degree)
                return FALSE; 
        }
    }

    return TRUE;
}

int del_node_by_pointer(node_t *head, node_t *node) 
{
    if (head == NULL) 
        return STACK_UNDERFLOW;

    for (; head->next != node && head != node; head = head->next);

    if (head == node)
        head = node->next;
    else
        head->next = node->next;

    free(node);

    return OK;
}

int list_copy(node_t *head, node_t **head_copy)
{
    for (; head; head = head->next)
    {
        if (push(head_copy, head->coefficient, head->degree) != OK)
        {
            list_free(*head_copy);
            return MEMORY_ALLOCATION_ERROR;
        }
    }

    if (reverse(head_copy) != OK)
        return MEMORY_ALLOCATION_ERROR;

    return OK;
}

node_t *find_var_degree(node_t *head, node_t *node)
{
    for (; head; head = head->next)
    {
        if (head->degree == node->degree)
            return head;
    }

    return NULL;
}

int insert_node(node_t **head, node_t *node)
{
    node_t *temp_head = *head, *temp_node = node_init(node->coefficient, node->degree);

    if (temp_node == NULL)
        return MEMORY_ALLOCATION_ERROR;
    
    for (; temp_head->next && temp_head->next->degree > temp_node->degree; temp_head = temp_head->next);
    
    if (temp_node->degree > temp_head->degree)
    {
        temp_node->next = *head;
        *head = temp_node;       
    }
    else
    {
        temp_node->next = temp_head->next;
        temp_head->next = temp_node;
    }

    return OK;
}
