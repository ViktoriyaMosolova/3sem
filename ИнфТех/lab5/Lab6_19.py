from math import *

def x(cb):
    x = cb / (1900 - 18 * cb)
    return x

def T(t):
    return t + 273.15

def n(cb, t):
    try:
        n = 10 ** (-1.52 + ((0.065 + x(cb)) / (19.147 * T(t))) * (140845 - 4.4429 * pow(10, 7) * ((T(t) - 273.15) / T(t) ** 2)))
        return n
    except ZeroDivisionError:
        print("На 0 делить нельзя")
        exit(0)
def n1(cb1, t1):
    try:
        n1 = 10 ** (-1.52 + ((0.065 + x(cb1)) / (19.147 * t1)) * (140845 - 4.4429 * pow(10, 7) * ((t1 - 273.15) / t1 ** 2)))
        return n1
    except ZeroDivisionError:
        print("На 0 делить нельзя")
        exit(0)
print("Введите диапазон для CB(концентрация чистого сахарного раствора, определённая высушиванием) CB1 - начальная точка, CB2 - конечная точка, ΔCB - шаг")
try:
    a = int(input("CB1 = "))
    b = int(input("CB2 = "))
    c = int(input("ΔCB = "))
except ValueError:
        print("Это не число. Попробуйте снова")
        exit(0)

print("Введите диапазон для Температуры в градусах Цельсия T1 - начальная точка, T2 - конечная точка, ΔT - шаг")
try:
    q = int(input("T1 = "))
    w = int(input("T2 = "))
    e = int(input("ΔT = "))
except ValueError:
    print("Это не число. Попробуйте еще раз.")
    exit(0)
for cb in range(a, b + c, c):
    for t in range(q, w + e, e):
        print("cb = ", cb, "t = ", T(t), "t(C) = ", t, "n = ", n(cb, t))
        exp1 = (0.65 - n(0, 40)) * 100
        exp2 = (4.94 - n(50, 50)) * 100
        exp3 = (2.5 - n(30, 30)) * 100
print(abs(exp1), "%")
print(abs(exp2), "%")
print(abs(exp3), "%")
print('\n')
try:
    with open('input.txt', 'r') as file:
        file.readline()
        a = int(file.readline())
        b = int(file.readline())
        c = int(file.readline())
        file.readline()
        q = int(file.readline())
        w = int(file.readline())
        e = int(file.readline())
        with open('output.txt', 'w') as f:
            f.write("{:7} {:8} {:10} {}\n".format("CB", "T(K)", "T(C)", "n"))
            CB = list(range(a, b+c, c))
            Temp = list(map(lambda x: x + 273.15, range(q, w+e, e)))
            for cb1 in CB:
                for t1 in Temp:
                    f.write("{:2} {:10} {:6} {:11.5f}\n".format(cb1, t1, int(t1-273.15), n1(cb1, t1)))
except FileNotFoundError:
    print("Не удалось найти файл")
    exit(0)
"""
print('\n')
print("Zadanie 5 sposob 2.2")
CB1 = sorted(list(range(0, 50+10, 10))*7)
Temp1 = list(map(lambda i: i + 273.15, range(20, 50+5, 5)))*6
N = list(map(lambda a, b: 10 ** (-1.52 + ((0.065 + x(a)) / (19.147 * b)) * (140845 - 4.4429 * pow(10, 7) * ((b - 273.15) / b ** 2))), CB1, Temp1))
print(N)
"""
