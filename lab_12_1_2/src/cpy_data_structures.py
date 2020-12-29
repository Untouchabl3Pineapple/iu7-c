import ctypes

class vector_t(ctypes.Structure):
    _fields_ = [("vector", ctypes.c_void_p),
                ("len", ctypes.c_int)]

# STRUCTURES INIT

vector1 = vector_t()
vector2 = vector_t()
