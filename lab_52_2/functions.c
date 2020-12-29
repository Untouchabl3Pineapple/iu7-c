#include "functions.h"

size_t file_size(FILE *f)
{
    size_t size;
    
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    rewind(f);
    
    return size;
}

void get_structure(FILE *f, const int position, shop *product)
{
    fseek(f, position * sizeof(shop), SEEK_SET);
    fread(product, sizeof(shop), 1, f);
}

void put_structure(FILE *f, const int position, shop *product)
{
    fseek(f, position * sizeof(shop), SEEK_SET);
    fwrite(product, sizeof(shop), 1, f);
}

int sort_file(FILE *f_in, shop *product, shop *temp_product)
{
    if (f_in == NULL)
        return FILE_READING_ERROR;
    if (file_size(f_in) < sizeof(shop))
        return FILE_READING_ERROR;
    
    size_t size = file_size(f_in) / sizeof(shop);

    for (size_t i = 0; i < size - 1; i++)
    {
        for (size_t j = 0; j < size - 1; j++)
        {
            get_structure(f_in, j, temp_product);
            get_structure(f_in, j + 1, product);
            if (temp_product->price < product->price || \
                (temp_product->price == product->price \
                && temp_product->amount < product->amount))
            {
                put_structure(f_in, j, product);
                put_structure(f_in, j + 1, temp_product);
            }
        }
    }
    rewind(f_in);

    return OK;
}

int output_in_file(FILE *f_in, FILE *f_out, shop *product)
{
    if (f_in == NULL)
        return FILE_READING_ERROR;
    if (f_out == NULL)
        return FILE_READING_ERROR;
    
    size_t size = file_size(f_in) / sizeof(shop);
    
    for (size_t i = 0; i < size; i++)
    {
        fread(product, sizeof(shop), 1, f_in);
        fwrite(product, sizeof(shop), 1, f_out);
    }

    if (fclose(f_in) == EOF)
        return FILE_CLOSE_ERROR;
    if (fclose(f_out) == EOF)
        return FILE_CLOSE_ERROR;

    return OK;
}

int is_substr_in_name(char *const substr, shop *product)
{
    int len_substr = strlen(substr);
    int i = 0;

    if (strstr(product->name, substr) == NULL)
        return FALSE;
    
    for (; strstr(&product->name[i], substr) != NULL; i++);
    
    if (product->name[i + len_substr - 1] == '\0')
        return TRUE;
    
    return FALSE;
}

int print_product_with_exception(FILE *f_in, char *const substr, shop *product)
{
    if (f_in == NULL)
        return FILE_READING_ERROR;
    if (file_size(f_in) < sizeof(shop))
        return FILE_READING_ERROR;
    
    size_t size = file_size(f_in) / sizeof(shop);
      
    int flag = FALSE;
    for (size_t i = 0; i < size; i++)
    {
        fread(product, sizeof(shop), 1, f_in);
        if (is_substr_in_name(substr, product) == TRUE)
        {
            flag = TRUE;
            printf("%s\n", product->name);
            printf("%s\n", product->manufacturer);
            printf("%d\n", product->price);
            printf("%d\n", product->amount);
        }
    }
    
    if (flag == FALSE)
        return STR_NOT_FOUND;
    if (ferror(f_in) != 0)
        return FILE_READING_ERROR;
    
    if (fclose(f_in) == EOF)
        return FILE_CLOSE_ERROR;

    return OK;
}

int product_input(FILE *f_in, shop *temp_product)
{
    printf("name :");
    if (fgets(temp_product->name, NAME_SIZE + 1, stdin) == NULL)
        return INPUT_ERROR;
    
    printf("manuf :");
    if (fgets(temp_product->manufacturer, MANUFACTURER_SIZE + 1, stdin) == NULL)
        return INPUT_ERROR;
    
    printf("price :");
    if (fscanf(stdin, "%u", &temp_product->price) != 1)
        return INPUT_ERROR;
    
    printf("amount :");
    if (fscanf(stdin, "%u", &temp_product->amount) != 1)
        return INPUT_ERROR;
    
    temp_product->name[strlen(temp_product->name) - 1] = '\0';
    temp_product->manufacturer[strlen(temp_product->manufacturer) - 1] = '\0';
    
    rewind(f_in);
    
    return OK;
}

int insert_in_file(FILE *f_in, shop *product, shop *temp_product)
{
    if (f_in == NULL)
        return FILE_READING_ERROR;
    if (file_size(f_in) < sizeof(shop))
        return FILE_READING_ERROR;
    if (product_input(f_in, temp_product) != 0)
        return INPUT_ERROR;
    
    size_t size = file_size(f_in) / sizeof(shop) + 1;
    
    // main insert (up to the penultimate structure)
    for (size_t i = 0; i < size - 2; i++)
    {
        get_structure(f_in, i, product);
        if (temp_product->price > product->price || \
            (temp_product->price == product->price \
            && temp_product->amount > product->amount))
        {
            printf("%zu", i);
            put_structure(f_in, i, temp_product);
            get_structure(f_in, i + 1, temp_product);
            put_structure(f_in, i + 1, product);
        }
    }
    
    // additional insert (last 2 structures)
    if (size != 2)
    {
        get_structure(f_in, size - 2, product);
        if (temp_product->price > product->price || \
            (temp_product->price == product->price \
            && temp_product->amount > product->amount))
        {
            put_structure(f_in, size - 2, temp_product);
            put_structure(f_in, size - 1, product);
        }
        else
        {
            put_structure(f_in, size - 2, product);
            put_structure(f_in, size - 1, temp_product);
        }
    }
    else
    {
        get_structure(f_in, 0, product);
        if (temp_product->price > product->price || \
            (temp_product->price == product->price \
            && temp_product->amount > product->amount))
        {
            put_structure(f_in, 0, temp_product);
            put_structure(f_in, 1, product);
        }
        else
        {
            put_structure(f_in, 0, product);
            put_structure(f_in, 1, temp_product);
        }
    }
            
    if (ferror(f_in) != 0)
        return FILE_READING_ERROR;
    
    if (fclose(f_in) == EOF)
        return FILE_CLOSE_ERROR;

    return OK;
}
