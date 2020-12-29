#include "functions.h"

int main(int argc, char **argv)
{
    int test;
    shop product, temp_product;
    
    memset(&product, 0, sizeof(product));
    memset(&temp_product, 0, sizeof(temp_product));
    
    if (argc < 3 || argc > 4)
        return ARGC_ERROR;
    
    if (strcmp(argv[1], "sb") != 0 && strcmp(argv[1], "fb") \
        != 0 && strcmp(argv[1], "ab") != 0)
        return ARGC_ERROR;
        
    if (strcmp(argv[1], "sb") == 0)
    {
        if (argc != 4)
            return ARGC_ERROR;
        FILE *f_in = fopen(argv[2], "rb+"), *f_out = fopen(argv[3], "wb");
        test = sort_file(f_in, &product, &temp_product);
        test += output_in_file(f_in, f_out, &product);
        if (test != 0)
            return test;
    }
    
    if (strcmp(argv[1], "fb") == 0)
    {
        if (argc != 4)
            return ARGC_ERROR;
        FILE *f_in = fopen(argv[2], "rb");
        test = print_product_with_exception(f_in, argv[3], &product);
        if (test != 0)
            return test;
    }
    
    if (strcmp(argv[1], "ab") == 0)
    {
        if (argc != 3)
            return ARGC_ERROR;
        FILE *f_in = fopen(argv[2], "rb+");
        test = insert_in_file(f_in, &product, &temp_product);
        if (test != 0)
            return test;
    }
        
    return OK;
}
