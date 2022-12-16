from scipy import integrate
from random import randint

print(integrate.quad(lambda x: x**4 + 3*x**2 + 10, 0, 5))