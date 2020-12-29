#include "../inc/data_structures.h"
#include "../inc/memory_lib.h"
#include "../inc/io_lib.h"
#include "../inc/file_lib.h"
#include "../inc/data_size_lib.h"
#include "../inc/process_lib.h"

int main(void)
{
    char filename[FILENAME_SIZE];
    vector_t vector1, vector2;  

    // ______________________________________
  
    fill_filename(filename);

    FILE *file = file_open(filename);

    // ______________________________________

    vector1.len = get_data_size(file);

    vector1.vector = vector_alloc(vector1.vector, vector1.len);

    file_rewind(file);

    fill_data(vector1, file);

    vector2.vector = vector_alloc(vector2.vector, vector1.len);

    // _______________COMMAND_1______________

    print_vector(vector1);

    left_cyclic_shift(vector1, 2);

    print_vector(vector1);

    // _______________COMMAND_2______________

    print_vector(vector1);

    parse_full_squares(vector1, &vector2);

    print_vector(vector2);

    // ______________________________________

    vector_free(vector1.vector);

    vector_free(vector2.vector);

    file_close(file);

    // ______________________________________

    return OK;
}
