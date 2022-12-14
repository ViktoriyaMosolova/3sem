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

from math import pow

def computation(t, sv):
    try:
        x = sv / (1900 - 18 * sv)
        y = pow(10, (22.46 * x - 0.114 + ((30 - t) / (91 + t)) * (1.1 + 43.1 * pow(x, 1.25))))
        return y
    except ZeroDivisionError:
        print("Деление на 0")
        exit(1)

##для считывания с консоли
try:
    t=input("Введите диапазон t(oC) и шаг через пробел(a b step): ")
    sv=input("Введите диапазон СВ(%) и шаг через пробел(a b step): ")
    t=list(map(float, t.split(sep=" ")))
    sv=list(map(float, sv.split(sep=" ")))
except ValueError:
    print("input_console:Не те значения!!Нужно ввести диапазон и шаг для численных параметров через пробел(a b step)!!!\n")
    exit(1)
except KeyboardInterrupt:
    print("input_console:Не нажимайте клавиши для прерывания процесса!!\n")
    exit(1)
except EOFError:
    print("input_console:Неожиданный символ конца файла!!\n")
    exit(1)

if (len(sv)!=3 or len(t)!=3):
    print("input_console:Нужно ввести по 3 значения для каждого параметра. "
        "Диапазон и шаг через пробел(a b step)\n")
    exit(1)

flag=0
if ((t[0] < -273.15) or (t[1] < -273.15)):
    print("input_console:Температура не может быть менее -273.15oC\n")
    flag=1
if ((sv[0] < 0) or (sv[1] < 0) or (sv[0] > 100) or (sv[1] > 100)):
    print("input_console:Значение концентрации не может быть более 100% или менее 0%\n")
    flag=1
if flag==1: 
    exit(1)

try:
    step_t=int((t[1]-t[0])/t[2])
    step_sv=int((sv[1]-sv[0])/sv[2])
    t0=t[0]
    sv0=sv[0]
except ZeroDivisionError:
    print("input_console:Шаг не может быть 0")
    exit(1)

try:
    for i in range(step_t+1):
        t0=t[0]+i*t[2]
        for j in range(step_sv+1):
            sv0=sv[0]+j*sv[2]
            print(f"t(oC)={t0:<12.3f}sv(%)={sv0:<12.3f}n(sP)={computation(t0, sv0):<12.3f}")
    dt=[40,50,30]
    dsv=[0,50,30]
    n_real=[0.65,4.94,2.5]
    for i in range(3):
        n_comp=computation(dt[i], dsv[i])
        dn=abs((n_real[i] - n_comp) * 100)
        print(f"t(oC)={dt[i]:<12.3f}sv(%)={dsv[i]:<12.3f}n_real(sP)={n_real[i]:<12.3f}n_comp(sP)={n_comp:<12.3f}n_error(%)={dn:<12.3}")
except OverflowError:
    print("input_console:Слишком большой результат")
    exit(1)
except KeyboardInterrupt:
    print("input_console:Не нажимайте клавиши для прерывания процесса!!\n")
    exit(1)
except EOFError:
    print("input_console:Неожиданный символ конца файла!!\n")
    exit(1)


##для считывания с файла
try:
    with open("input_file.txt", "r") as d:
        t_f=list(map(float, d.readline().split(sep=" "))) 
        sv_f=list(map(float, d.readline().split(sep=" "))) 
    d.close()
except ValueError:
    print("input_file:Не те значения!!Нужно ввести диапазон и шаг для численных параметров через пробел(a b step)!!!\n")
    exit(1)
except FileNotFoundError:
    print("input_file:Не удалось найти файл")
    exit(1)
except OSError:
    print("input_file:Системная ошибка\n")
    exit(1)

if (len(sv_f)!=3 or len(t_f)!=3):
    print("input_file:Нужно ввести по 3 значения для каждого параметра. "
        "Диапазон и шаг через пробел(a b step)\n")
    exit(1)

flag=0
if ((t_f[0] < -273.15) or (t_f[1] < -273.15)):
    print("input_file:Температура не может быть менее -273.15oC\n")
    flag=1
if ((sv_f[0] < 0) or (sv_f[1] < 0) or (sv_f[0] > 100) or (sv_f[1] > 100)):
    print("input_file:Значение концентрации не может быть более 100% или менее 0%\n")
    flag=1
if flag==1: 
    exit(1)

try:
    step_t_f=int((t_f[1]-t_f[0])/t_f[2])
    step_sv_f=int((sv_f[1]-sv_f[0])/sv_f[2])
    t0_f=t_f[0]
    sv0_f=sv_f[0]
except ZeroDivisionError:
    print("input_file:Шаг не может быть 0")
    exit(1)

with open("output_file.txt", "w") as f:
    try:
        for i in range(step_t_f+1):
            t0_f=t_f[0]+i*t_f[2]
            for j in range(step_sv_f+1):
                sv0_f=sv_f[0]+j*sv_f[2]
                f.write(f"t(oC)={t0_f:<12.3f}sv(%)={sv0_f:<12.3f}n(sP)={computation(t0_f, sv0_f):<12.3f}\n")
        dt_f=[40,50,30]
        dsv_f=[0,50,30]
        n_real_f=[0.65,4.94,2.5]
        for i in range(3):
            n_comp_f=computation(dt_f[i], dsv_f[i])
            dn_f=abs((n_real_f[i] - n_comp_f) * 100)
            f.write(f"t(oC)={dt_f[i]:<12.3f}sv(%)={dsv_f[i]:<12.3f}n_real(sP)={n_real_f[i]:<12.3f}n_comp(sP)={n_comp_f:<12.3f}n_error(%)={dn_f:<12.3f}\n")
    except OverflowError:
        print("input_file:Слишком большой результат")
        exit(1)
f.close()
