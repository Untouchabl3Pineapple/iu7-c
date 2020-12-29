#include "../inc/sort.h"

int compare(const void *x, const void *y)
{
    return (*(int *)x - *(int *)y);
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (head == NULL || comparator == NULL)
        return NULL;

    node_t *head_sorted = NULL;

    for (node_t *next; head; head = next)
    {
        next = head->next;

        sorted_insert(&head_sorted, head, comparator);
    }

    return head_sorted;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    if (*head == NULL)
    {
        element->next = *head;
        *head = element;
    }
    else
    {
        node_t *temp_head = *head;
        
        for (; temp_head->next && comparator(element->data, temp_head->next->data) > 0; \
            temp_head = temp_head->next);
    
        if (comparator(temp_head->data, element->data) > 0)
        {
            element->next = *head;
            *head = element;       
        }
        else
        {
            element->next = temp_head->next;
            temp_head->next = element;
        }
    }
}
