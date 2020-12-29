#include "../inc/my_snprintf.h"

int get_size_end_format(const char *format, va_list arg)
{
    int size = 0;
    specifiers_t specif;

    while (*format)
    {
        if (my_strncmp(format, "%d", DIGIT_SPECIFIER_SIZE) == EQUAL)
        {
            specif.d = va_arg(arg, int);
            size += number_size(specif.d, "all");

            format += DIGIT_SPECIFIER_SIZE;
        }
        else if (my_strncmp(format, "%ld", LONG_DIGIT_SPECIFIER_SIZE) == EQUAL)
        {
            specif.ld = va_arg(arg, long);
            size += number_size(specif.ld, "all");

            format += LONG_DIGIT_SPECIFIER_SIZE;
        }
        else if (my_strncmp(format, "%c", CHAR_SPECIFIER_SIZE) == EQUAL)
        {
            specif.c = va_arg(arg, int);
            size += CHAR_SIZE;

            format += CHAR_SPECIFIER_SIZE;
        }
        else
        {
            size += CHAR_SIZE;

            format += CHAR_SIZE;
        }
    }

    LOG_DEBUG("END_SIZE %d", size);

    return size;
}

int my_snprintf(char *buffer, int buf_size, const char *format, ...)
{   
    char *str;
    int buf_real_size = 0;
    int format_end_size;

    specifiers_t specif;
    va_list arg;

    if (buffer != NULL)
        BUFFER_INIT;

    va_start(arg, format);

    while (*format && buf_size - CHAR_SIZE > 0 && buffer != NULL)
    {
        if (my_strncmp(format, "%d", DIGIT_SPECIFIER_SIZE) == EQUAL)
        {
            specif.d = va_arg(arg, int);
            buf_real_size += number_size(specif.d, "all");

            str = integer_to_string(specif.d, &buf_size);
            my_strncat(buffer, str, my_strlen(str));
            free(str);

            format += DIGIT_SPECIFIER_SIZE;
        }
        else if (my_strncmp(format, "%ld", LONG_DIGIT_SPECIFIER_SIZE) == EQUAL)
        {
            specif.ld = va_arg(arg, long);
            buf_real_size += number_size(specif.ld, "all");

            str = integer_to_string(specif.ld, &buf_size);
            my_strncat(buffer, str, my_strlen(str));
            free(str);

            format += LONG_DIGIT_SPECIFIER_SIZE;
        }
        else if (my_strncmp(format, "%c", CHAR_SPECIFIER_SIZE) == EQUAL)
        {
            specif.c = va_arg(arg, int);
            buf_real_size += CHAR_SIZE;

            int temp_buf_size = my_strlen(buffer);

            buffer[temp_buf_size] = specif.c;
            buffer[temp_buf_size + CHAR_SIZE] = '\0';

            format += CHAR_SPECIFIER_SIZE;
            buf_size -= CHAR_SIZE;
        }
        else
        {
            buf_real_size += CHAR_SIZE;

            my_strncat(buffer, format, CHAR_SIZE);

            format += CHAR_SIZE;
            buf_size -= CHAR_SIZE;
        }
    }

    format_end_size = get_size_end_format(format, arg);

    va_end(arg);
    
    return buf_real_size + format_end_size;
}
