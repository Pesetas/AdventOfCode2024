#---------------------#
# Advent of code 2024 #
# Dia 1, ejercicio 1  #
#---------------------#

lista_izq = []
lista_der = []

with open('input.txt', 'r') as archivo:
    for linea in archivo:
        numeros = linea.split()
        lista_izq.append(int(numeros[0]))
        lista_der.append(int(numeros[1]))

lista_izq.sort()
lista_der.sort()

size = len(lista_izq)

sum = 0

for i in range(0, size, 1):
    num = lista_izq[i] - lista_der[i]
    if num < 0:
        num = num * -1 
    sum += num
print(sum)
