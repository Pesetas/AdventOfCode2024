#---------------------#
# Advent of code 2024 #
# Dia 2, ejercicio 1  #
#---------------------#

def ascendente(linea):
    size = len(linea)
    for i in range(1, size):
        if (
            (linea[i-1] < linea[i]) and
            ((linea[i] - linea[i-1]) < 4) and 
            ((linea[i] - linea[i-1]) > 0)
        ):
            continue
        else:
            return 0
    return 1
    
def descendente(linea):
    size = len(linea)
    for i in range(1, size):
        if (
            (linea[i-1] > linea[i]) and
            ((linea[i-1] - linea[i]) < 4) and 
            ((linea[i-1] - linea[i]) > 0)
        ):
            continue
        else:
            return 0
    return 1
    
sum = 0;

with open('input.txt', 'r') as archivo:
    for linea in archivo:
        linea = linea.split()
        linea = [int(char) for char in linea]
        sum += ascendente(linea)
        sum += descendente(linea)
        print(sum)