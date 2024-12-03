#---------------------#
# Advent of code 2024 #
# Dia 3, ejercicio 1  #
#---------------------#

import re

with open("input.txt", 'r') as archivo:
    texto = archivo.read()
regex = r"mul\((\d+),(\d+)\)"
resultados = re.findall(regex, texto)
suma_total = sum(int(a) * int(b) for a, b in resultados)

print(suma_total)
