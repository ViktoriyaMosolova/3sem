from math import tan

x=float(input())
x1=float(input())

def func(x):
    return lambda x1: tan(x+x1)

print(func(x)(x1))