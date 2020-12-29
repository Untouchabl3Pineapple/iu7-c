#include "../inc/str_functions.h"

char *my_strncat(char *destptr, const char *srcptr, const size_t len)
{
    if (destptr == NULL || srcptr == NULL) 
        return NULL;

    size_t start_destp = my_strlen(destptr), end_srcp = my_strlen(srcptr);
    size_t i = start_destp;
    
    for (size_t j = 0; j < end_srcp && j < len; i++, j++)
    {
        destptr[i] = srcptr[j];
    }

    destptr[i] = '\0';

    LOG_DEBUG("DESTPTR %s", destptr);

    return destptr;
}

size_t my_strlen(const char *str)
{
    if (str == NULL)
        return NULL_POINTER;

    size_t len = 0;

    for (; *str; str++)
    {
        len++;
    }

    LOG_DEBUG("STR_LEN %zu", len);

    return len;
}

int number_size(long number, char *const filter)
{
    int len = 0;

    /*
    *   all - size with a minus sign
    *   abs - size without minus sign
    */
    
    if (my_strncmp(filter, "all", 3) == 0 && number < 0)
        len++;

    if (number < 0)
        number *= -1;
    
    for (unsigned long numb = number; numb > 9; numb /= 10)
    {
        len++;
    }

    LOG_DEBUG("NUMBER_SIZE %d", len + 1);

    return ++len;
}

char *integer_to_string(long number, int *const buf_size)
{
    int i = 0;
    int size = number_size(number, "abs");

    char *str = (char *) malloc((size + 2) * sizeof(char));

    if (str == NULL)
        return NULL;

    if (number < 0)
    {
        number *= -1;
        (*buf_size)--;
        str[i++] = '-';
    }
    
    for (unsigned long numb = number; size > 0 && *buf_size > 0; size--, (*buf_size)--, i++)
    {
        str[i] = numb / (unsigned long) pow(10, size - 1) + '0';
        numb %= (unsigned long) pow(10, size - 1);
    }

    if (*buf_size > 0)
        str[i] = '\0'; 
    else
        str[--i] = '\0';

    LOG_DEBUG("INT_TO_STRING %s", str);
    
    return str;
}

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    if (str1 == NULL || str2 == NULL)
        return NULL_POINTER;

    for (size_t i = 0; i < n; i++)
    {
        if (str1[i] != str2[i])
        {
            if (str1[i] > str2[i])
                return GREATER;
            else
                return LESS;
        }
    }

    return EQUAL;
}
