from library_load import *
from cpy_data_structures import *

import ctypes

def pfile_open(lib, filename):

    lib.file_open.argtypes = [ctypes.c_char_p, ]
    lib.file_open.restype = ctypes.c_void_p

    file = lib.file_open(filename.encode("utf-8"))

    return file

def pget_data_size(lib, file):

    lib.get_data_size.argtypes = [ctypes.c_void_p, ]
    lib.get_data_size.restype = ctypes.c_int

    size = lib.get_data_size(file)

    return size

def pvector_alloc(lib, vector, vector_len):

    lib.vector_alloc.argtypes = [ctypes.c_void_p, ctypes.c_int, ]
    lib.vector_alloc.restype = ctypes.c_void_p

    vector = lib.vector_alloc(vector, vector_len)

    return vector

def pfile_rewind(lib, file):

    lib.file_rewind.argtypes = [ctypes.c_void_p, ]
    lib.file_rewind.restype = ctypes.c_void_p

    lib.file_rewind(file)

def pfill_data(lib, vector, file):

    lib.fill_data.argtypes = [vector_t, ctypes.c_void_p, ]
    lib.fill_data.restype = ctypes.c_int

    lib.fill_data(vector, file)

def pprint_vector(lib, vector):

    lib.print_vector.argtypes = [vector_t, ]
    lib.print_vector.restype = ctypes.c_void_p

    lib.print_vector(vector)

def pleft_cyclic_shift(lib, vector, kposc):

    lib.left_cyclic_shift.argtypes = [vector_t, ctypes.c_int, ]
    lib.left_cyclic_shift.restype = ctypes.c_void_p

    lib.left_cyclic_shift(vector, kposc)

def pparse_full_squares(lib, vector, parse_vector):

    lib.parse_full_squares.argtypes = [vector_t, ctypes.POINTER(vector_t), ]
    lib.parse_full_squares.restype = ctypes.c_void_p

    lib.parse_full_squares(vector, parse_vector)

def pvector_free(lib, vector):

    lib.vector_free.argtypes = [ctypes.c_void_p, ]
    lib.vector_free.restype = ctypes.c_void_p

    lib.vector_free(vector)

def file_close(lib, file):

    lib.file_close.argtypes = [ctypes.c_void_p, ]
    lib.file_close.restype = ctypes.c_void_p

    lib.file_close(file)



