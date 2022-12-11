# 16. Вычислить значение суммы F1 и F2 для диапазона аргументов х. Шаг по х принять 0.1 для
# обычных функций и 0,05π если диапазон х задан диапазона в долях π.
# Примечание. Учитывать вероятность возникновения ошибок при вычислениях. 
from math import log, pi, sqrt, tan
a = 2
b = 4
c = 3
y = 6

step = int((4*pi-pi)/(0.05*pi))
x0 = pi
print(step)
for i in range(step):
    x = x0+i*(0.05*pi)
    t1 = (a*x)/y + (b/(y*y)) * log(10, y*x+c)
    if ((c*c-b*b) < 0) or ((sqrt(c*c-b*b) * tan(a*x) - 2) == 0) or ((sqrt(c*c-b*b) * tan(a*x) + 2)/(sqrt(c*c-b*b) * tan(a*x) - 2) < 0): 
        print("t2 не определено")
    else:
        t2 = (1/(2*a*b)) * log((sqrt(c*c-b*b) * tan(a*x) + 2)/(sqrt(c*c-b*b) * tan(a*x) - 2))
        print(t1 + t2)
