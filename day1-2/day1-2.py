#---------------------#
# Advent of code 2024 #
# Dia 1, ejercicio 2  #
#---------------------#

lista_izq = []
lista_der = []

with open('input.txt', 'r') as archivo:
    for linea in archivo:
        numeros = linea.split()
        lista_izq.append(int(numeros[0]))
        lista_der.append(int(numeros[1]))

size = len(lista_izq)

sum = 0
rep = 0

for i in range(0, size, 1):
    rep = lista_der.count(lista_izq[i])
    sum += (rep * lista_izq[i])

print(sum)
