import numpy as np
import sys

def reading(name):
    with open(str(name), 'r') as f:
        #l = [[float(num) for num in line.split(',') if num != '\n'] for line in f]
        l = eval(f.read().replace('\n', ''))
    return np.matrix(l)

def norm_det(matrix):
    prod=1
    for row in matrix:
            prod*=np.linalg.norm(row)

    det = np.abs(
            np.linalg.det(matrix)
        )
    print(f'Determinante: {det}')
    print(f'Denominador: {prod}')
    if prod == 0:
        return "A matriz possui linha nula!"
    return det/prod

matrix = reading(sys.argv[1])
print(f'Determinante normalizado: {norm_det(matrix)}')