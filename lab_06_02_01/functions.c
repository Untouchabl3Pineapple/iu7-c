#include "functions.h"

int parse_args(int argc, char **argv, char *filename, char *filter)
{
    if (argc < LOWER_LIMIT_ARGC || argc > UPPER_LIMIT_ARGC)
        return ARGS_ERROR;

    strcpy(filename, argv[1]);
    if (argc == 3)
        strcpy(filter, argv[2]);
    
    return OK;
}

int input_inform(description *items_array, \
int *items_len, FILE *file)
{
    int weight_test, volume_test;

    for (int i = 0; !feof(file); i++, (*items_len)++)
    {
        if (fgets(items_array[i].title, TITLE_SIZE, file) == NULL)
            return TITLE_SIZE_ERROR;
        if (strlen(items_array[i].title) == TITLE_SIZE - 1)
            return TITLE_SIZE_ERROR;

        weight_test = fscanf(file, "%f\n", &items_array[i].weight);
        volume_test = fscanf(file, "%f\n", &items_array[i].volume);

        if (!weight_test || weight_test == EOF)
            return FILE_READING_ERROR;
        if (!volume_test || volume_test == EOF)
            return FILE_READING_ERROR;

        if (items_array[i].weight <= 0 || items_array[i].volume <= 0)
            return WEIGHT_VOLUME_ERROR;

        if (*items_len == ARRAY_SIZE - 1)
            return ARRAY_SIZE_ERROR;
    }

    return OK;
}

void print_structure(const description *const items_array, const int index)
{
    printf("%s", items_array[index].title);
    printf("%.6f\n", items_array[index].weight);
    printf("%.6f\n", items_array[index].volume);
}

void print_inform(const description *const items_array, \
const int items_len, int argc, char *filter)
{
    for (int i = 0; i < items_len; i++)
    {
        if (argc == 2 || strcmp(filter, "ALL") == OK)
            print_structure(items_array, i);
        else
        {
            if (strncmp(filter, items_array[i].title, \
            strlen(filter)) == OK)
                print_structure(items_array, i);
        }
    }
}

void insertion_sort(description *items_array, const int items_len)
{
    for (int i = 1; i < items_len; i++)
    {
        description buffer = items_array[i];
        int j = i - 1;
        float start_el = START_ELEMENT_RES;
        for (; TEMP_ELEMENT > start_el && j >= 0;)
        {
            items_array[j + 1] = items_array[j];
            j--;
            if (j < 0)
                break;
        } 
        items_array[j + 1] = buffer;
    }
}
