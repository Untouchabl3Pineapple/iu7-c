#include "../inc/unit_cmp.h"

int is_equal(node_t *head_1, node_t *head_2)
{
    for (; head_1;)
    {
        if (head_2 == NULL)
            return FALSE;

        if (head_1->coefficient != head_2->coefficient || \
            head_1->degree != head_2->degree)
            return FALSE;

        head_1 = head_1->next;
        head_2 = head_2->next;
    }

    if (head_2 != NULL)
        return FALSE;
    
    return TRUE;
}
