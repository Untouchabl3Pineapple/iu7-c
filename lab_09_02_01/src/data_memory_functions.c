#include "../inc/data_memory_functions.h"

int array_allocate(item_t **items_array, int *const items_len, FILE *file)
{
    char *line = NULL;
    size_t len = 0;

    for (; getline(&line, &len, file) != -1; (*items_len)++);
    free(line);
    *items_len /= 3;

    LOG_DEBUG("ITEMS_LEN=%d", *items_len);
    
    *items_array = (item_t*)malloc(*items_len * sizeof(item_t));
    if (!*items_array)
        return ALLOCATION_ERROR;
    
    rewind(file);

    return OK;
}

int string_allocate(char **title, FILE *file)
{
    *title = NULL;
    size_t len = 0;

    if (getline(title, &len, file) == -1)
        return FILE_READING_ERROR;

    return OK;
}

void data_free(item_t **items_array, int index)
{
    for (int i = 0; i < index; i++)
    {
        free((*items_array)[i].title);
    }
    free(*items_array);
}
