# Переводить значение давления, заданного в паскалях (Па), атмосферах (атм.) или мм. ртутного
# столба друг в друга. 1 атм = 101 325 Па = 760 мм. рт. ст. 

atm = float(input("atm: "))
pa = atm * 101325
mrs = atm * 760 
print(f"{atm} atm = {pa} pa = {mrs} mrs")

pa = float(input("pa: "))
atm = pa / 101325
mrs = atm * 760
print(f"{atm} atm = {pa} pa = {mrs} mrs")

mrs = float(input("mrs: "))
atm = mrs / 760
pa = atm * 101325
print(f"{atm} atm = {pa} pa = {mrs} mrs")
