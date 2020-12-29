#include "../inc/io.h"

int parse_args(const int argc, char **const argv, int *const args_number, \
char *filename, char *filter)
{
    if (argc < LOWER_LIMIT_ARGC || argc > UPPER_LIMIT_ARGC)
        return ARGS_ERROR;

    *args_number = argc;
    strcpy(filename, argv[1]);
    if (argc == 3)
        strcpy(filter, argv[2]);
    
    return OK;
}

int input_inform(item_t *items_array, const int items_len, FILE *file)
{
    for (int i = 0, weight_test, volume_test; i != items_len; i++)
    {
        if (string_allocate(&items_array[i].title, file) != OK)
        {
            data_free(&items_array, i + 1);
            return FILE_READING_ERROR;
        }

        weight_test = fscanf(file, "%f\n", &items_array[i].weight);
        volume_test = fscanf(file, "%f\n", &items_array[i].volume);

        LOG_DEBUG("WEIGHT=%s", items_array[i].title);
        LOG_DEBUG("WEIGHT=%f", items_array[i].weight);
        LOG_DEBUG("VOLUME=%f", items_array[i].volume);

        if (weight_test != 1 || weight_test == EOF || \
        volume_test != 1 || volume_test == EOF)
        {
            data_free(&items_array, i + 1);
            return FILE_READING_ERROR;
        }

        if (items_array[i].weight <= 0 || items_array[i].volume <= 0)
        {
            data_free(&items_array, i + 1);
            return WEIGHT_VOLUME_ERROR;
        }
    }

    return OK;
}

void print_structure(const item_t *const items_array, const int index)
{
    printf("%s", items_array[index].title);
    printf("%.6f\n", items_array[index].weight);
    printf("%.6f\n", items_array[index].volume);
}

void print_inform(const item_t *const items_array, const int items_len, \
const int args_number, char *const filter)
{
    for (int i = 0; i < items_len; i++)
    {
        if (args_number == 2 || strcmp(filter, "ALL") == OK)
            print_structure(items_array, i);
        else if (strncmp(filter, items_array[i].title, strlen(filter)) == OK)
            print_structure(items_array, i);
    }
}

int is_empty(FILE *file)
{
    if (fgetc(file) == EOF)
    {
        if (fclose(file) == EOF)
            return FILE_CLOSE_ERROR;
        return FILE_READING_ERROR;
    }

    rewind(file);

    return OK;
}