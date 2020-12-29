#include "process.h"

/*
max_1 - main maximum, max_2 - additional maximum
*/

int process(FILE *f, int *const max_1, int *const max_2)
{
    int numb;
    int flag_max_1 = FALSE, flag_max_2 = FALSE;
    
    if (f == NULL)
        return NULL_POINTER_ERROR;
    
    while (fscanf(f, "%d", &numb) == TRUE)
    {
        if (flag_max_1 == FALSE)
        {
            *max_1 = numb;
            flag_max_1 = TRUE;
        }
        else if (numb >= *max_1)
        {
            *max_2 = *max_1;
            *max_1 = numb;
            flag_max_2 = TRUE;
        }
        else if (flag_max_2 == FALSE)
        {
            *max_2 = numb;
            flag_max_2 = TRUE;
        }
        else if (numb > *max_2)
            *max_2 = numb;
    }
    
    if (flag_max_1 == FALSE || flag_max_2 == FALSE)
        return MAX_NUMB_NONE;
    
    return OK;
}
