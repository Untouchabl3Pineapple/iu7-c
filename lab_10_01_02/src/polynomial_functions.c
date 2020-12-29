#include "../inc/polynomial_functions.h"

int polynomial_value(node_t *head, const int var)
{
    int value = 0;

    for (; head; head = head->next)
    {
        value += head->coefficient * pow(var, head->degree);
    }

    LOG_DEBUG("POLYNOMIAL_VALUE: %d", value);

    return value;
}

node_t *polynomial_derivative(node_t *head)
{
    for (; head; head = head->next)
    {
        if (head->degree != 0)
            head->coefficient *= head->degree--;
        else
            return head;
    }

    return head;
}

int polynomial_sum(node_t *head, node_t *head_1, node_t **head_sum)
{
    if (list_copy(head, head_sum) != OK)
    {
        list_free(head);
        list_free(head_1);
        return MEMORY_ALLOCATION_ERROR;
    }

    node_t *temp_node;
    node_t *temp_head_1 = head_1, *temp_head_sum = *head_sum;

    /*
        Summing variables with the same degrees
    */

    for (; temp_head_sum; temp_head_sum = temp_head_sum->next) 
    {
        temp_node = find_var_degree(head_1, temp_head_sum);
        if (temp_node != NULL)
            temp_head_sum->coefficient += temp_node->coefficient;  
    }

    /*
        Insert the missing variables
    */

    for (; temp_head_1; temp_head_1 = temp_head_1->next)
    {
        temp_node = find_var_degree(*head_sum, temp_head_1);
        if (temp_node == NULL)
        {
            if (insert_node(head_sum, temp_head_1) != OK)
            {
                list_free(head);
                list_free(head_1);
                list_free(*head_sum);
                return MEMORY_ALLOCATION_ERROR;
            }
        }
    }

    return OK;
}

int polynomial_degree_separation(node_t *head, node_t **head_even, node_t **head_odd)
{
    for (; head; head = head->next)
    {
        if (head->degree % 2 == 0)
        {
            if (push(head_even, head->coefficient, head->degree) != OK)
            {
                list_free(head);
                list_free(*head_even);
                list_free(*head_odd);
                return MEMORY_ALLOCATION_ERROR;
            }
        }
        else
        {
            if (push(head_odd, head->coefficient, head->degree) != OK)
            {
                list_free(head);
                list_free(*head_even);
                list_free(*head_odd);
                return MEMORY_ALLOCATION_ERROR;
            }
        }
    }

    if (reverse(head_even) != OK)
    {
        list_free(head);
        list_free(*head_odd);
        return MEMORY_ALLOCATION_ERROR;
    }
    if (reverse(head_odd) != OK)
    {
        list_free(head);
        list_free(*head_even);
        return MEMORY_ALLOCATION_ERROR;
    }

    return OK;
}
