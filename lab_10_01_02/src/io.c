#include "../inc/io.h"

int filter_fill(char *const filter)
{
    if (fgets(filter, FILTER_SIZE + 2, stdin) == NULL)
        return FILTER_FILLING_ERROR;

    if (strlen(filter) == FILTER_SIZE + 1)
        return FILTER_FILLING_ERROR;
    
    DELETING_NEW_LINE_IN_FILTER;

    if (strcmp(filter, "val") != 0 && strcmp(filter, "ddx") != 0 \
        && strcmp(filter, "sum") != 0 && strcmp(filter, "dvd") != 0)
        return FILTER_FILLING_ERROR;

    return OK;
}

int read_line(char **line)
{
    *line = NULL;
    size_t line_len = 0;

    if (getline(line, &line_len, stdin) == -1)
    {
        free(line);
        return READ_LINE_ERROR;
    }

    return OK;
}

int number_size(int number)
{
    int len = 0;

    if (number < 0)
        len++;

    for (; number > 10; number /= 10)
    {
        len++;
    }

    LOG_DEBUG("NUMBER_SIZE: %d", len + 1);

    return ++len;
}

int list_fill(node_t **head)
{
    char *line;

    if (read_line(&line) != OK)
    {
        list_free(*head);
        return READ_LINE_ERROR;
    }
    
    for (int readed_count = 0, coefficient, degree, rc; \
        (readed_count < strlen(line));)
    {
        rc = sscanf(line + readed_count, "%d", &coefficient);
        if (rc == 0 || rc == EOF)
        {
            free(line);
            list_free(*head);
            return LIST_FILLING_ERROR;
        }
        readed_count += number_size(coefficient) + 1;

        rc = sscanf(line + readed_count, "%d", &degree);
        if (rc == 0 || rc == EOF)
        {
            free(line);
            list_free(*head);
            return LIST_FILLING_ERROR;
        }
        readed_count += number_size(degree) + 1;

        if (degree < 0)
        {
            free(line);
            list_free(*head);
            return LIST_FILLING_ERROR;
        }
        
        if (push(head, coefficient, degree) != OK)
        {
            free(line);
            list_free(*head);
            return MEMORY_ALLOCATION_ERROR;
        }

        LOG_DEBUG("LINE_LEN: %lu", strlen(line));
        LOG_DEBUG("READED_COUNT: %d", readed_count);
    }

    free(line);

    if (decrease_degree_check(*head) != TRUE)
    {
        list_free(*head);
        return INCORRECT_SEQUENCE;
    }

    return OK;
}

void list_print(node_t *head)
{
    for (; head; head = head->next)
    {
        printf("%d ", head->coefficient);
        printf("%d ", head->degree);
    }
    printf("L\n");
}
