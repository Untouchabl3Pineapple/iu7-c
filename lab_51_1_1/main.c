#include "process.h"

int main(void)
{
    int max_1, max_2;
    int test = process(stdin, &max_1, &max_2);
    
    if (test != OK)
        return test;
    
    printf("%d %d", max_2, max_1);
    
    return OK;
}
