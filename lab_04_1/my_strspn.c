#include "my_strspn.h"

int find_char(const int temp, const char *str2)
{
    int flag = FALSE;
    
    for (int j = 0; str2[j] != '\0'; j++)
    {
        if (str2[j] == temp)
            flag = TRUE;
    }
    
    return flag;
}

size_t my_strspn(const char *str1, const char *str2)
{
    size_t i = 0;
    
    for (; str1[i] != '\0'; i++)
    {
        int temp = str1[i];
        if (find_char(temp, str2) == FALSE)
            return i;
    }
    
    return i;
}
