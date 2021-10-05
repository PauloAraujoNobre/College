def func1(x, y, z, w):
  return abs(pow(x, 2) + pow(y, 3) + pow(z, 4) - pow(w, 5))

def func2(x, z, w):
  return abs(pow(x, 2) + (3 * pow(z, 2)) - w)

def func3(z, y):
  return abs(pow(z, 5) - y - 10)

def func4(x, y, z, w):
  return abs(pow(x, 4) - z + (y * w))

def getError(v):
  x, y, z, w = setVariables(v)

  sum = 0
  sum += func1(x, y, z, w)
  sum += func2(x, z, w)
  sum += func3(y, z)
  sum += func4(x, y, z, w)

  erro = "{:.8f}".format(1 / (1 + sum))

  return erro

def setVariables(vetor):
  x = vetor[0]
  y = vetor[1]
  z = vetor[2]
  w = vetor[3]

  return x, y, z, w

if __name__ == "__main__":
  x = int(input("Digite o valore de X: \n"))
  y = int(input("Digite o valore de Y: \n"))
  z = int(input("Digite o valore de Z: \n"))
  w = int(input("Digite o valore de W: \n"))

  vetor = [x, y, z, w]
  oldValue = getError(vetor)

  operation = 1
  indice = 0
  iteracao = 2000

  while (iteracao > 0):
    if indice > 3:
      break
    vetorAux = vetor
    vetorAux[indice] += operation
    newValue = getError(vetorAux)
    if newValue < oldValue:
      oldValue = newValue
      vetor = vetorAux
    else:
      if operation == 1:
        operation = -1
      else:
        operation = 1
        indice += 1

    iteracao -= 1

  print("Vetor: \n", vetor)
  print("Erro: \n", oldValue)