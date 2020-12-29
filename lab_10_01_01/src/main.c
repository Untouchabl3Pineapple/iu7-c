#include "../inc/constants.h" 
#include "../inc/data_structures.h"
#include "../inc/io.h"
#include "../inc/memory_functions.h" 
#include "../inc/list_functions.h"
#include "../inc/sort.h"

int main(const int argc, const char **const argv)
{
    int rc;
    int number_del;
    node_t *head = NULL;
    int args_number;
    char filename_in[FILE_IN_NAME_SIZE] = { '\0' };
    char filename_out[FILE_OUT_NAME_SIZE] = { '\0' };

    if (parse_args(argc, argv, &args_number, filename_in, filename_out) != OK)
        return ARGS_ERROR;

    FILE *file_in = fopen(filename_in, "r");
    if (file_in == NULL)
        return FILE_READING_ERROR;

    if (fgetc(file_in) == EOF)
    {
        if (fclose(file_in) == EOF)
            return FILE_CLOSE_ERROR;
        return FILE_READING_ERROR;
    }
    rewind(file_in);
    
    rc = fill_data(&head, &number_del, file_in);
    if (rc != OK)
    {
        list_free(head);
        if (fclose(file_in) == EOF)
        {
            list_free(head);
            return FILE_CLOSE_ERROR;
        }
        return rc;
    }

    if (del_numbs(&head, number_del) != OK)
    {
        list_free(head);
        if (fclose(file_in) == EOF)
        {
            list_free(head);
            return FILE_CLOSE_ERROR;
        }
        return UNDERFLOW_ERROR;
    }

    if ((head = sort(head, compare)) == NULL)
    {
        list_free(head);
        if (fclose(file_in) == EOF)
        {
            list_free(head);
            return FILE_CLOSE_ERROR;
        }
        return SORT_ERROR;
    }

    FILE *file_out = fopen(filename_out, "w");
    if (file_out == NULL)
    {
        list_free(head);
        if (fclose(file_in) == EOF)
        {
            list_free(head);
            return FILE_CLOSE_ERROR;
        }
        return FILE_READING_ERROR;
    }

    fill_file(file_out, head);

    list_free(head);
    
    if (fclose(file_in) == EOF)
    {
        list_free(head);
        return FILE_CLOSE_ERROR;
    }

    if (fclose(file_out) == EOF)
    {
        list_free(head);
        return FILE_CLOSE_ERROR;
    }

    return OK;
}
