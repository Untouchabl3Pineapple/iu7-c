#include "functions.h"

void print_matrix(char (*m)[COLUMN], const int ind)
{
    printf("Result: ");
    for (int i = 0; i != ind; i++)
    {
        for (int j = 0; j != strlen(m[i]); j++)
            printf("%c", m[i][j]);
        if (i + 1 != ind)
            printf(" ");
    }
    printf("\n");
}

int compare(const void *a, const void *b)
{
    return strcmp((char*)a, (char*)b);
}

int is_dublicate(char (*m)[COLUMN], char *const word, const int ind)
{
    for (int i = 0; i != ind; i++)
    {
        if (strcmp(m[i], word) == 0)
            return TRUE;
    }
    
    return FALSE;
}

int condition_test(char *const str, char (*m)[COLUMN], int *ind)
{
    // input str
    printf("Input str: ");
    if (fgets(str, STR_SIZE + 2, stdin) == NULL)
        return LEN_ROW_ERROR;
    
    // len row check
    if (strlen(str) == STR_SIZE + 1)
        return LEN_ROW_ERROR;
    
    // string without words check
    int element_counter = 0;
    int k = 0;
    long int first_ind, second_ind;
    
    first_ind = strpbrk(&str[k], " ,;:-.!?") - str;
    for (; str[k] != '\0'; k++)
    {
        second_ind = strpbrk(&str[k], " ,;:-.!?") - str;
        if (second_ind != first_ind)
        {
            first_ind = second_ind;
            element_counter++;
        }
    }
    if (k - 1 == element_counter)
        return LEN_ROW_ERROR;

    // input words in array
    char word[WORD_SIZE] = { 0 };
    long int limit;

    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '\n')
            continue;
         
        // the index space
        limit = strpbrk(&str[i], " ,;:-.!?") - str;
         
        // char in str == 1 and strlen != 0 (copy word in array and clear array)
        if (i == limit && strlen(word) != 0)
        {
            if (is_dublicate(m, word, *ind) == FALSE)
            {
                strcpy(m[*ind], word);
                memset(word, 0, sizeof(word));
                (*ind)++;
            }
            else
                memset(word, 0, sizeof(word));
        }
        // recurring char
        else if (i == limit)
            continue;
        else
        {
            // wordSize check
            if (strlen(word) >= WORD_SIZE - 1)
                return LEN_WORD_ERROR;
            // add one char in temp array
            strncat(word, &str[i], 1);
        }
    }
    // add last word in seq
    if (is_dublicate(m, word, *ind) == FALSE && strlen(word) != 0)
    {
        strcpy(m[*ind], word);
        memset(word, 0, sizeof(word));
        (*ind)++;
    }
    else
        memset(word, 0, sizeof(word));
    
    return OK;
}
