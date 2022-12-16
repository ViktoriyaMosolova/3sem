'''7.3 Операции над матрицами c использованием NumPy и SciPy (Z3) 
6. Решить произвольную систему из 3-х линейных алгебраических уравнений. 
Проверить точность решения. '''

from numpy import array
from scipy.linalg import solve

#   4*x+5*y+z/2=0
#   x/10+40*y+z=5
#   x-5*y-2*z=10

A = array([ [4,5,1/2],
            [1/10,40,1],
            [1,-5,-2] ])
A = array([ [1,2,3],
            [4,5,6],
            [7,8,9.0000001] ])
b = array([0,5,10])
x=solve(A,b)
print(x)