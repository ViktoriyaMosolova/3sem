'''Вариант 5 – 28'''

from math import *


n_ras = []
p = 0
T = 0

a1 = -1.528
a2 = 0.00153
a3 = 763.67999
a4 = 2.30351
a5 = -0.00261
T0 = 175.


try:
    # with open('data.txt', 'r') as data:  # Преобразуем данные из файла
    #     k = list(data)
    # p = list(map(float, k[1].split(sep=",")))
    # T = list(map(float, k[3].split(sep=",")))

    p = list(map(float, input("Введите параметр p через пробел: ").split(sep=" ")))  # Преобразуем введенные значения
    T = list(map(float, input("Введите параметр T через пробел: ").split(sep=" ")))

    output = open("output.txt", "w")
    output.write("Полученные расчетные значения(мПа*с):\n")

    for i in range(len(T)):
        if (T[i] <= 274.0):
            print("Введите температуру в К")
            exit(1)
    for i in range(len(p)):
        if (p[i] <= 1e-7):
            print("Введите давление в Mpa")
            exit(1)

    print("Полученные расчетные значения:")
    for i in range(len(p)):
        for j in range(len(T)):
                n_ras = exp(a1 + a2 * p[i] + (a3 + a4 * p[i] + a5 * pow(p[i], 2)) / (T[j] - T0))
                output.write(str(n_ras))
                output.write("\t")
                print(n_ras, end='\t')
        output.write("\n")
        print("\n")


    output.close()
except TypeError:
    print("Введите  числа через запятую (например 5.4, 42)!")
    exit(1)
except FileNotFoundError:
    print("Не найден исходный файл!")
    exit(1)
except EOFError:
    print("Неожиданный конец файла!")
    exit(1)
except ValueError:
    print("Введите числа через запятую (например 5.4, 42)!")
    exit(1)
except OverflowError:
    print("Полученное число слишком большое!")
    exit(1)
except ZeroDivisionError:
    print("Произошло деление на ноль!")
    exit(1)
except KeyboardInterrupt:
    print("\nВведите данные с клавиатуры!")