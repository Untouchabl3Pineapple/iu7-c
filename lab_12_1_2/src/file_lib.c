#include "../inc/file_lib.h"

FILE *file_open(char *const filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
        return NULL;

    return file;
}

void file_rewind(FILE *file)
{
    rewind(file);
}

void file_close(FILE *file)
{
    fclose(file);
}
