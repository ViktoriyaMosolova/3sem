import numpy as np
from numpy import fabs

maximum = 1.0
e = 0.001
D = [0]
c = [[0], [0]]
x_new = [0]
V = 0.5
g = 1
N = 7
i = 0
j = 1

def seidel(A,B,x0):
    fr = open('result-2.txt', 'w')

    global err
    A = np.array(A, dtype=float)
    B = np.array(B, dtype=float)
    x0 = np.array(x0, dtype=float)
    count = 0
    maximum = 1.0
    e = 0.001

    while True:
        count += 1
        for i in range(N):
            x_new[i] = 0
            err[i] = 0
            for j in range(N):
                x_new[i] += c[i][j] * x_new[i - 1][j]
            x_new[i] += D[i]
            err = fabs(x_new[i] - x0[i])
            maximum = max(err)
        print(count)
        Res = str(count)
        fr.write(Res)
        fr.write('\n')
        for i in range(N):
            fr.write(x0[i])
            x0[i] = x_new[i]
        fr.write('\n')
        if maximum < e:
            break
    fr.close()
    return count

def lyambda (P):
    return -((P/fabs(P) * V) / (g + fabs(P)))

def Cij (A, c):
    A = np.array(A, float)
    c = np.array(c, float)
    j = 0
    for i in range(N):
        l = lyambda(A[i][i])
        for j in range(N):
            if i == j:
                c[i][j] = 1 + A[i][j] * l
            else:
                c[i][j] = A[i][j] * l

def Di(B, A, D):
    A = np.array(A, float)
    B = np.array(B, float)
    D = np.array(D, float)
    for i in range(N):
        D[i] = - lyambda(A[i][i]) * B[i]


A = [[13.9, 9.4, 9.0, 3.2, -3.7, -10.1, 8.1],
     [-4.3, 15.2, 1.1, -6.0, -8.2, 2.8, -5.0],
     [8.8, 9.6, 17.7, 9.8, 10.9, 1.5, 8.6],
     [4.6, -1.1, 1.0, 1.0, -4.8, 8.7, 4.0],
     [12.1, -13.8, 0.5,19.5, 12.1, 0.5, 11.9],
     [5.1, 15.4, 11.9, 2.1, 26.5, -2.5, 13.0],
     [6.4, -6.6, 7.1, -2.8, -9.0, -4.5, 13.2]]

B = [-23.61, 128.71, 27.03, -22.77, -179.40, 25.81, -92.47]

x0 = [-0.1, -1.0, -0.9, -1.7, 2.0, -1.0, -0.7]

Cij(A, c)
print("\nC:\n")
for i in range(N):
    for j in range(N):
        print(c[i][j])

Di(B, A, D)
print("\nD:\n")
for i in D:
    print(D)
print('\n')
Y = seidel(A, B, x0)
print(Y)

