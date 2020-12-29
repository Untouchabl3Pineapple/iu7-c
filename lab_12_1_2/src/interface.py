from tkinter import *
from tkinter import messagebox as mb

from library_load import *
from cpy_functions import *
from cpy_data_structures import *

def iget_data(e1):  

    global file # :3

    file = pfile_open(lib, e1.get())

    if file is None:
        mb.showerror("Ошибка", "Неправильно введено название файла")
        return

    vector1.len = pget_data_size(lib, file)
    vector1.vector = pvector_alloc(lib, vector1.vector, vector1.len)

    pfile_rewind(lib, file)
    pfill_data(lib, vector1, file)

    vector2.vector = pvector_alloc(lib, vector2.vector, vector1.len)

    pprint_vector(lib, vector1)

def ipleft_cyclic_shift(e2):

    if vector1.vector is None:
        mb.showerror("Ошибка", "Для начала введите файл")
        return

    try:
        int(e2.get())
    except:
        mb.showerror("Ошибка", "Введите корректное количество смещений (>= 0)")
        return
    
    if int(e2.get()) < 0:
        mb.showerror("Ошибка", "Введите корректное количество смещений (>= 0)")
        return

    pleft_cyclic_shift(lib, vector1, int(e2.get()))
    pprint_vector(lib, vector1)

def ipparse_full_squares():

    if vector1.vector is None:
        mb.showerror("Ошибка", "Для начала введите файл")
        return

    pparse_full_squares(lib, vector1, vector2)
    pprint_vector(lib, vector2)

def iexit():

    if vector1.vector is None:
        exit()

    pvector_free(lib, vector1.vector)
    pvector_free(lib, vector2.vector)

    file_close(lib, file)

    exit()

def main():

    window = Tk()
    window.title("From Artemev Ilya with love <3")  
    window.geometry('600x200')  

    lbl = Label(window, text="Функции\n")
    lbl.grid(column=0, row=0)

    lb1 = Label(window, text="Ввод названия файла")
    lb1.grid(column=0, row=4)
    lb2 = Label(window, text="Циклический свдиг массива на k позиций влево")
    lb2.grid(column=0, row=5)
    lb3 = Label(window, text="Заполнение второго массива отфильтрованными данными")  
    lb3.grid(column=0, row=6)
    lb4 = Label(window, text="Выход")  
    lb4.grid(column=0, row=7)  

    e1 = Entry(window,width=10)  
    e1.grid(column=1, row=4)
    e2 = Entry(window,width=10)  
    e2.grid(column=1, row=5)

    b1 = Button(window, text="Выполнить", command=lambda: iget_data(e1))
    b1.grid(column=2, row=4)
    b2 = Button(window, text="Выполнить", command=lambda: ipleft_cyclic_shift(e2))
    b2.grid(column=2, row=5)
    b3 = Button(window, text="Выполнить", command=ipparse_full_squares)
    b3.grid(column=1, row=6)
    b4 = Button(window, text="Выполнить", command=iexit)
    b4.grid(column=1, row=7)

    window.mainloop()


if __name__ == "__main__":
    main()