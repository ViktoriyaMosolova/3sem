z, z1, z2, z3 = 64.496, 0.0659625, 0.224306, 0.105729
x, x1, x2, x3 = 64.496, 0.066027, 0.2241304e-2, 0.10560396e-4
c, c1, c2 = 64.4724, 8.1564207e-2, 2.3034122e-4
c3, c4 = 2.6492852e-5, 2.4826037e-8
v, v1, v2 = 64.18, 0.1348, 5.31e-4
b, b1, b2 = 63.608, 0.133, 7.22e-4
t = [0, 10, 20, 30, 40, 50, 60, 70, 80, 90]
CX = []
try:
    with open('vhod.txt') as f:
        text = f.read()
    CX = text.split(",")
    for i in range(len(CX)):
        CX[i] = float(CX[i])
except ValueError:
    print("В файле присутствует неправильное значение")


    
print("\t\tZadanie 1")
srznac = 0
CX1, CX2, CX3, CX4, CX5 = 0, 0, 0, 0, 0
for i in range(len(CX)):
    srznac = srznac + CX[i]
print("Ср. знач CX: ", srznac/len(CX))
for i in t:
    CX1 = round(CX1 + (z + z1 * i + z2 * pow(10, -2) * pow(i, 2) - z3 * pow(10, -4) * pow(i, 3)), 3)
print("Для формулы 1 ср.знач: ", CX1/len(CX))
for i in t:
    CX2 = round(CX2 + (x + x1 * i + x2 * pow(i, 2) - x3 * pow(i, 3)), 3)
print("Для формулы 2 ср.знач: ", CX2/len(CX))
for i in t:
    CX3 = round(CX3 + (c + c1 * i + c2 * pow(i, 2.8) - c3 * pow(i, 3.3) + c4 * pow(i, 4.5)), 3)
print("Для формулы 3 ср.знач: ", CX3/len(CX))
for i in t:
    CX4 = round((CX4 + (v + v1 * i + v2 * pow(i, 2))), 3)
print("Для формулы 4 ср.знач: ", CX4/len(CX))
for i in t:
    CX5 = round((CX5 + (b + b1 * i + b2 * pow(i, 2))), 3)
print("Для формулы 5 ср.знач: ", CX5/len(CX))
print("Наиболее подходящая формула: 4")
f = open('vihod.txt', 'w')
f.write('Задание 1\nНаиболее подходящая формула: 4')
f.close()

print("\n\t\tZadanie2")
srzn = 0
s1 = list(map(lambda num: round(z + z1 * num + z2 * pow(10, -2) * (num ** 2) - z3 * pow(10, -4) * (num ** 3), 3), t))
for i in range(len(s1)):
    srzn = srzn + s1[i]
print("Формула 1:", s1, "\nср.знач.:", round(srzn/len(s1), 3))
srzn = 0
s2 = list(map(lambda num: round(x + x1 * num + x2 * (num ** 2) - x3 * (num ** 3), 3), t))
for i in range(len(s2)):
    srzn = srzn + s2[i]
print("Формула 2:", s2, "\nср.знач.:", round(srzn/len(s2), 3))
srzn = 0
s3 = list(map(lambda num: round(c + c1 * num + c2 * pow(num, 2.8) - c3 * pow(num, 3.3) + c4 * pow(num, 4.5), 3), t))
for i in range(len(s3)):
    srzn = srzn + s3[i]
print("Формула 3:", s3, "\nср.знач.:", round(srzn/len(s3), 3))
srzn = 0
s4 = list(map(lambda num: round(v + v1 * num + v2 * (num ** 2), 3), t))
for i in range(len(s4)):
    srzn = srzn + s4[i]
try:
    print("Формула 4:", s4, "\nср.знач.:", round(srzn/len(s4), 3))
except ZeroDivisionError:
    print("В s4 нет элементов, программа пытается делить на ноль.")
srzn = 0
s5 = list(map(lambda num: round(b + b1 * num + b2 * (num ** 2), 3), t))
for i in range(len(s5)):
    srzn = srzn + s5[i]
try:
    print("Формула 5:", s5, "\nср.знач.:", round(srzn/len(s5), 3))
except ZeroDivisionError:
    print("В s5 нет элементов, программа пытается делить на ноль.")
print("Наиболее подходящая формула: 4")
f = open('vihod.txt', 'a')
f.write('\n\nЗадание 2\nНаиболее подходящая формула: 4')
f.close()