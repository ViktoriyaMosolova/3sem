# 3.1 Списки (Z1) 
#
# 13. Создать список А из 10 повторяющихся строк "abcс" (т.е. ["abcс", "abcс",…"abcс"])
# a. Расширить список А, вставив перед последним элементом в нём кортеж (1, 3, 6) .
# b. Вывести в консоль упорядоченный по убыванию предпоследний элемент А (т.е. кортеж)
# c. Вывести в консоль количество символов "с" в последней строке списка А.

A = ["abcc"] * 10
A.insert(-1,(1,2,3))
l = reversed(sorted((A[-2])))
print(tuple(l))
print(A[-1].count('c'))