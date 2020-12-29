#include "functions.h"

int main(int argc, char **argv)
{
    int test;
    
    if (argc < 3 || argc > 4)
        return ARGC_ERROR;
    
    if (strcmp(argv[1], "c") != 0 && strcmp(argv[1], "p") \
        != 0 && strcmp(argv[1], "s"))
        return ARGC_ERROR;
        
    if (strcmp(argv[1], "c") == 0)
    {
        if (argc != 4)
            return ARGC_ERROR;
        FILE *f = fopen(argv[3], "wb");
        test = create_file(f, atoi(argv[2]));
        if (test != 0)
            return test;
    }
    
    if (strcmp(argv[1], "p") == 0)
    {
        if (argc != 3)
            return ARGC_ERROR;
        FILE *f = fopen(argv[2], "rb");
        test = print_file(f);
        if (test != 0)
            return test;
    }
    
    if (strcmp(argv[1], "s") == 0)
    {
        if (argc != 3)
            return ARGC_ERROR;
        FILE *f = fopen(argv[2], "rb+");
        test = sort(f);
        if (test != 0)
            return test;
    }
        
    return OK;
}
