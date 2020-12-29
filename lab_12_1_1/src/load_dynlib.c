#include "../inc/load_dynlib.h"

int load_library(void)
{
    void *lib = dlopen("lib/libiu7.so", RTLD_NOW);
    if (lib == NULL) 
        return LIB_LOAD_ERROR;

    parse_args = dlsym(lib, "parse_args");
    if (parse_args == NULL)
        return PARSE_ARGS_LOAD_ERROR;

    scan_file_len = dlsym(lib, "scan_file_len");
    if (scan_file_len == NULL)
        return SCAN_FILE_LEN_LOAD_ERROR;

    fill_array = dlsym(lib, "fill_array");
    if (fill_array == NULL)
        return FILL_ARRAY_LOAD_ERROR;

    fill_file = dlsym(lib, "fill_file");
    if (fill_file == NULL)
        return FILL_FILE_LOAD_ERROR;

    compare = dlsym(lib, "compare");
    if (compare == NULL)
        return COMPARE_LOAD_ERROR;

    mysort = dlsym(lib, "mysort");
    if (mysort == NULL)
        return MYSORT_LOAD_ERROR;

    key = dlsym(lib, "key");
    if (key == NULL)
        return KEY_LOAD_ERROR;

    return OK;
}
