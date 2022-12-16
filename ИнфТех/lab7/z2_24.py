'''7.2 Библиотека Numpy. Действия над массивами (Z2) 
24. Создать массив 2*3 заполненный случайными целыми числами от 23 до 69. 
Транспонировав массив,
отнять от каждого элемента массива 17 и вставить после 1-й позиции столбец [0, 0]. '''

import numpy as np
a = np.random.randint(23,70,(2,3),dtype=int) #interval [low, high)
print(f'a:\n{a}\n')
a=np.transpose(a)
print(f'a_transpose:\n{a}\n')
a-=17
print(f'a=a-17:\n{a}\n')
a=np.insert(a, 1, [0,0], axis=0)
print(f'add[0,0]:\n{a}\n')