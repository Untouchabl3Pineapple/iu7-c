#include "functions.h"

int create_file(FILE *f, const int numb)
{
    if (f == NULL)
        return FILE_READING_ERROR;
    if (numb < 1)
        return NUMBER_OF_ELEMENTS_ERROR;
    
    srand(time(NULL));
    for (int i = 0; i < numb; i++)
    {
        int element = rand();
        fwrite(&element, sizeof(int), 1, f);
    }
    
    if (fclose(f) == EOF)
        return FILE_CLOSE_ERROR;
    
    return OK;
}

int print_file(FILE *f)
{
    int element;
    
    if (f == NULL)
        return FILE_READING_ERROR;
    if (file_size(f) < sizeof(int))
        return FILE_READING_ERROR;

    while (TRUE)
    {
        if (fread(&element, sizeof(int), 1, f) != 1 && feof(f) == 0)
            return FILE_READING_ERROR;
        if (feof(f) != 0)
            break;
        printf("%d\n", element);
    }
    
    if (fclose(f) == EOF)
        return FILE_CLOSE_ERROR;
    
    return OK;
}

int get_number_by_pos(FILE *f, int position)
{
    int element;
    
    fseek(f, position * sizeof(int), SEEK_SET);
    fread(&element, sizeof(int), 1, f);
    
    return element;
}

void put_number_by_pos(FILE *f, int position, int number)
{
    fseek(f, position * sizeof(int), SEEK_SET);
    fwrite(&number, sizeof(int), 1, f);
}

size_t file_size(FILE *f)
{
    long int size;
    
    fseek(f, 0, SEEK_END);
    size = ftell(f);
    rewind(f);
    
    return size;
}

int sort(FILE *f)
{
    if (f == NULL)
        return FILE_READING_ERROR;
    if (file_size(f) < sizeof(int))
        return FILE_READING_ERROR;
    
    size_t size = file_size(f) / sizeof(int);
    
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            int first_element = get_number_by_pos(f, j);
            int second_element = get_number_by_pos(f, j + 1);
            if (first_element > second_element)
            {
                int temp = first_element;
                put_number_by_pos(f, j, second_element);
                put_number_by_pos(f, j + 1, temp);
            }
        }
    }
    
    if (fclose(f) == EOF)
        return FILE_CLOSE_ERROR;
    
    return OK;
}

