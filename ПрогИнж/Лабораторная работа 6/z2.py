x=int(input())
x2=int(input())

def f2(x):
    return lambda x2: x2*x2+x2+x

def f1(f2,x,x2): 
    print(f2)
    y = f2(x)(x2)+5
    return y

print(f1(f2,x,x2))
