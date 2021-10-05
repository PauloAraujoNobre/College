import math
import copy

infinito = float(math.inf)

def getTabuleiro():
  return [[None,None,None] for i in range(3)]

def terminal(tab):
  for i in tab:
    for j in i:
      if j==None: return False

  return True

def avalia(tab):
  for i in tab:
    if i.count(1) == 3: return 100
    if i.count(0) == 3: return -100
  
  for i in range(3):
    a = 0
    b = 0
    for j in tab:
      if j[i] == 1: a+=1
      if j[i] == 0: b+=1
    if a == 3: return 100
    if b == 3: return -100

  a = 0
  b = 0
  for i in range(3):
    if tab[i][i] == 1: a+=1
    if tab[i][i] == 0: b+=1
  if a == 3: return 100
  if b == 3: return -100
  
  a = 0
  b = 0
  for i in range(3):
    if tab[i][2-i] == 1: a+=1
    if tab[i][2-i] == 0: b+=1
  if a == 3: return 100
  if b == 3: return -100

  return 0

def disponiveis(st):
  return [(i, j) for i in range(len(st)) for j in range(len(st)) if st[i][j] == None]

def sucessores(estado):
  suc = []
  a, b = 0, 0
  for i in estado:
    for j in i:
      if j == 1:
        b+=1
      elif j == 0:
        a+=1
  if b > a:
    jog = 0
  else:
    jog = 1

  for i,j in disponiveis(estado):
    st = copy.deepcopy(estado)
    st[i][j] = jog
    suc.append(st)

  return suc
  
def fim (estado):
  res = avalia(estado)
  if res == 100:
    print("NPC ganhou")
    return True
  elif res == -100:
    print("Você ganhou")
    return True
  elif terminal(estado):
    print("Empatou")
    return True

  return False

def imprime(tab):
  print("\t=======================")
  for i in range(len(tab)):
    for j in range(len(tab)):
      print("\t {} ".format(tab[i][j]), end=" ")
    print()

def minimaxAlfaBeta(estado, jog = 1, alfa=infinito, beta=infinito):
  st = copy.deepcopy(estado)
  succ = sucessores(st)
  scores = []
  
  if  jog == 1:
    for i in succ:
      av = avalia(i)
      if av == 100 or av == -100 or terminal(i):
        scores.append(av)
      else:
        sc, st = minimaxAlfaBeta(i, 1-jog)
        if sc >= beta:
          return sc,st
        alfa = max(alfa,sc)
        scores.append(sc)

    scmax = max(scores)
    ind = scores.index(scmax)  
    return scmax,succ[ind]
  else: 
    for i in succ:
      av = avalia(i)
      if av == 100 or av == -100 or terminal(i):
        scores.append(av)
      else:
        sc, st = minimaxAlfaBeta(i, 1-jog)
        if sc >= alfa:
          return sc,st
        beta = max(beta,sc)
        scores.append(sc)

    scmin = min(scores)
    ind = scores.index(scmin)  
    return scmin,succ[ind]
  
def tutorial(tab):
  print("\t========Tutorial========")
  for i in range(len(tab)):
    for j in range(len(tab)):
      print("\t {} ".format((i + 1) + (j * 3)), end=" ")
    print()
  print("\t========================\n")
  input("Para começar, aperte Enter\n")
  return 0
  
def velha():
  print("Iniciando...")
  tab = getTabuleiro()
  jog = 1
  tutorialFlag = 1
  while True:
    jog = minimaxAlfaBeta(tab)
    if tutorialFlag == 1:
      tutorialFlag = tutorial(tab)
    imprime(jog[1])
    if fim(jog[1]): return
    while True:
      k = eval(input("Faça uma jogada de 1 a 8: \n")) - 1
      a,b = int(k/3), k%3
      if 0 <=k <= 8 and jog[1][a][b] == None: break
      print("Jogada invalida")
    jog[1][a][b] = 0
    imprime(jog[1])
    if fim(jog[1]): return
    tab = jog[1]

if __name__ == "__main__":
  velha()

