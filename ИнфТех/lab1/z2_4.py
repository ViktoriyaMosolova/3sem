# Выведите в консоль предложение "***Hello World! It is Python!*** ", разделив на слова с
# использованием сечения строк и удалив звёздочки с помощью одного из методов строк. Туда же в
# консоль выведите информацию о длинах каждой итоговой строки. 

string = "***Hello World! It is Python!*** "
result = string.replace('***', '') 
hello = result[0:5]
print(f"{hello} len=" + str(len(hello)))
world = result[6:11]
print(f"{world} len=" + str(len(world)))
it = result[13:15]
print(f"{it} len=" + str(len(it)))
iis = result[16:18]
print(f"{iis} len=" + str(len(iis)))
python = result[19:25]
print(f"{python} len=" + str(len(python)))
print(f"{hello} {world}! {it} {iis} {python}!")