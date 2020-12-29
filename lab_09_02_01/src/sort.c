#include "../inc/sort.h"

void insertion_sort(item_t *items_array, const int items_len)
{
    for (int i = 1, j; i < items_len; i++)
    {
        item_t buffer = items_array[i];
        j = i - 1;
        for (float start_el = DENSITY(items_array[i].weight, items_array[i].volume); \
        DENSITY(items_array[j].weight, items_array[j].volume) > start_el && j >= 0;)
        {
            items_array[j + 1] = items_array[j];
            j--;
            if (j < 0)
                break;
        } 
        items_array[j + 1] = buffer;
    }
}
