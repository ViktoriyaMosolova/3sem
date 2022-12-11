'''Выполнить задания PyCharm Edu раздела File Input/Output
• Добавить в программу по предыдущей лабораторной работе следующий функционал:

 Ввод пользователем исходных данных для расчёта с консоли и из текстового файла-задания.
Файл должен содержать необходимые пояснения к вводимым параметрам. Параметры должны
задавать весь вычисляемый диапазон, а не одну точку.

 Вывод в текстовой файл результатов расчёта в отформатированном табличном виде с
необходимой поясняющей информацией и размерностями входных и выходных величин.

 Перехват ошибок ввода-вывода (некорректные входные данные и некорректный диапазон
значений, отсутствие входного файла, неожиданный конец файла).

 Перехват ошибок расчёта (возможные арифметические ошибки и пр.). '''

from math import exp, pow

def computation(t, sv):
    try:
        x = sv / (1900 - 18 * sv)
        y = exp(22.46 * x - 0.114 + ((30 - t) / (91 + t)) * (1.1 + 43.1 * pow(x, 1.25)))
        return y
    except ZeroDivisionError:
        print("Деление на 0")

def file():
    try:
        with open("data.txt", "r") as d:
            p=list(map(float, d.readline().partition(":")[2].split(sep=","))) 
            sv=list(map(float, d.readline().partition(":")[2].split(sep=","))) 
           
        d.close()
        with open("output.txt", "w") as f:
            if len(sv)==len(p)==3:
                step_p=int((p[1]-p[0])/p[2])
                step_sv=int((sv[1]-sv[0])/sv[2])
                p0=p[0]
                sv0=sv[0]
                if len(sv)==len(p)==3:
                    for i in range(step_p):
                        p0=p[0]+i*step_p
                        for j in range(step_sv):
                            sv0=sv[0]+j*step_sv
                            f.write(f"p()={p0:<8}sv()={sv0:<8}n()={computation(p0, sv0):<8.8}\n")
            else:
                print("Введите одинаковое число параметров p и sv!!!")
        f.close()
    except FileNotFoundError:
        print("Не найден исходный файл data.txt. Создайте его и\nвведите значения p и sv таким образом:\n"
                "Values p: 5.4, 42\nValues sv: 5, 6.1\n")
    except ValueError:
        print("В файле присутствует неправильное значение\nВведите значения p и sv таким образом:\n"
            "Values p: 10 20 5\nValues sv: 10 20 5\n")
    

def input_stdin():
    try:
        print("Введите диапазон p и шаг:")
        p=input()
        p=list(map(float, p.split(sep=" ")))
        print("Введите диапазон СВ и шаг:")
        sv=input()
        sv=list(map(float, sv.split(sep=" ")))
        step_p=int((p[1]-p[0])/p[2])
        step_sv=int((sv[1]-sv[0])/sv[2])
        p0=p[0]
        sv0=sv[0]
        if len(sv)==len(p)==3:
            for i in range(step_p):
                p0=p[0]+i*step_p
                for j in range(step_sv):
                    sv0=sv[0]+j*step_sv
                    print("p =", p0, "sv =", sv0, "n =", computation(p0, sv0))
        else:
            print("Введите диапазон и шаг для p и СВ!!\n")
            input_stdin()
    except ValueError:
        print("В файле присутствует неправильное значение\nВведите значения p и sv таким образом:\n"
            "Values p:\n5.4, 42\nValues sv:\n5, 6.1\n")
        input_stdin()

def func():
    print("Введите 1 или 2 или 3:\n1.Ввод с файла\n2.Ввод с консоли\n3.Закрыть программу((")
    try:
        var_input=int(input())
        if var_input == 1:
            file()
        elif var_input == 2:
            input_stdin()
        elif var_input == 3:
            exit(1)
        else:
            print("Ошибка!!! Введите то, что написано...\n")
            func()
    except ValueError:
        print("Ошибка!Введите требуемые значения!!\n")
        func()
    except KeyboardInterrupt:
        print("Ошибка!Не прерывайте программу(\n")
        func()
    except EOFError:
        print("Ошибка!Программа наткнулась на символ конца файла...\n")
        func()

func()