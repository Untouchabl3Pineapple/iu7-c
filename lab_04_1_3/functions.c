#include "functions.h"

int is_same_words(char (*m)[COLUMN], const int ind)
{
    for (int i = 0; i != ind - 1; i++)
    {
        if (strcmp(m[ind - 1], m[i]) != 0)
            return FALSE;
    }
    
    return TRUE;
}

void chr_sort(char *temp_str, char *sorted_str)
{
    char temp_var;
    
    for (size_t i = 0; i != strlen(temp_str); i++)
    {
        temp_var = temp_str[i];
        if (strpbrk(&temp_var, sorted_str) != 0)
            continue;
        
        for (size_t j = 0; j != strlen(temp_str); j++)
        {
            if (strncmp(&temp_str[i], &temp_str[j], 1) == 0)
                strncat(sorted_str, &temp_str[i], 1);
        }
    }
}

void str_form(char (*m)[COLUMN], char *const new_str, const int ind)
{
    char temp_str[WORD_SIZE] = { 0 };
    char sorted_str[WORD_SIZE] = { 0 };
    char flag;
    
    for (int i = ind - 2; i != - 1; i--)
    {
        if (strcmp(m[i], m[ind - 1]) == TRUE)
        {
            if (i != 0 && i != ind - 2)
                strcat(new_str, " ");
            continue;
        }
        strcat(temp_str, m[i]);
        chr_sort(temp_str, sorted_str);
        flag = sorted_str[0];
        strncat(new_str, &flag, 1);
        for (int j = 0; sorted_str[j] != '\0'; j++)
        {
            if (strncmp(&flag, &sorted_str[j], 1) != 0)
            {
                flag = sorted_str[j];
                strncat(new_str, &flag, 1);
            }
        }
        memset(temp_str, 0, sizeof(temp_str));
        memset(sorted_str, 0, sizeof(sorted_str));
        if (i != 0)
        {
            if (strcmp(m[i - 1], m[ind - 1]) != TRUE)
                strcat(new_str, " ");
        }
    }
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
            strcpy(m[*ind], word);
            memset(word, 0, sizeof(word));
            (*ind)++;
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
    if (strlen(word) != 0)
    {
        strcpy(m[*ind], word);
        memset(word, 0, sizeof(word));
        (*ind)++;
    }
    else
        memset(word, 0, sizeof(word));
    
    if (*ind < WORDS_LIMIT)
        return ONE_WORD_ERROR;
    
    if (is_same_words(m, *ind) == TRUE)
        return SAME_WORDS_ERROR;
   
    return OK;
}
