 #include "../inc/io.h"

int parse_args(const int argc, const char **const argv, int *const args_number, \
char *filename_in, char *filename_out)
{
    if (argc != CORRECT_ARGS_NUMBER)
        return ARGS_ERROR;

    *args_number = argc;
    strcpy(filename_in, argv[1]);
    strcpy(filename_out, argv[2]);
    
    return OK;
}

int fill_data(node_t **head, int *const number_del, FILE *file_in)
{
    if (head == NULL)
        return DATA_FILLING_ERROR;

    if (fscanf(file_in, "%d", number_del) != 1)
        return DATA_FILLING_ERROR;
    
    if (*number_del < 0)
        return DATA_FILLING_ERROR;

    for (int rc, *data, number; (rc = fscanf(file_in, "%d", &number)) != EOF;)
    {
        if (rc != 1)
            return DATA_FILLING_ERROR;

        data = (int *)malloc(sizeof(int));
        if (data == NULL)
            return MEMORY_ALLOCATION_ERROR;

        *data = number;

        if (push(head, data) != OK)
            return MEMORY_ALLOCATION_ERROR;
    }

    if ((*head = reverse(*head)) == NULL)
        return REVERSE_ERROR;

    return OK;
}

void fill_file(FILE *file_out, node_t *head)
{
    for (; head; head = head->next)
    {
        fprintf(file_out, "%d ", *(int *)head->data);
    }
}

void list_print(node_t *head)
{
    for (; head; head = head->next)
    {
        printf("%d ", *(int *)head->data);
    }
    printf("\n");
}
