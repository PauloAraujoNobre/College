from random import randint
import timeit
import matplotlib as mpl
import matplotlib.pyplot as plt
import sys

def geraLista(tam):
    lista = list(range(tam, 0, -1))
    return lista

def plot_grafico(x, y, file_name, label1, xl = "Entradas", yl = "Saídas"):
    fig = plt.figure(figsize=(10, 8))
    ax = fig.add_subplot(111)
    ax.plot(x, y, label= label1)
    ax.legend(bbox_to_anchor=(1, 1),bbox_transform=plt.gcf().transFigure)
    plt.ylabel(yl)
    plt.xlabel(xl)

    fig.savefig(file_name)

def particao(lista, ini, fim):
  i = (ini - 1)
  pivo = lista[fim]

  for j in range(ini, fim):
    if lista[j] <= pivo:
      i = i+1
      lista[i], lista[j] = lista[j], lista[i]

  lista[i+1], lista[fim] = lista[fim], lista[i+1]
  return (i+1)

def quick_sort(lista, ini, fim):
    tam = fim - ini + 1
    pilha = [0] * (tam)
    topo = -1
    topo = topo + 1
    pilha[topo] = ini
    topo = topo + 1
    pilha[topo] = fim

    while topo >= 0:
        fim = pilha[topo]
        topo = topo - 1
        ini = pilha[topo]
        topo = topo - 1
        pivo = particao(lista, ini, fim)

        if pivo - 1 > ini:
            topo = topo + 1
            pilha[topo] = ini
            topo = topo + 1
            pilha[topo] = pivo - 1

        if pivo + 1 < fim:
            topo = topo + 1
            pilha[topo] = pivo + 1
            topo = topo + 1
            pilha[topo] = fim

if __name__ == '__main__':
    x = [100000, 200000, 500000, 1000000, 200000]
    y_des = []
    tempo_des = []

    for i in range(len(x)):
        y_des.append(geraLista(x[i]))

    for i in range(len(x)):

        tempo_des.append(timeit.timeit("quick_sort({},{},{})".format(y_des[i], 1, len(y_des[i]) - 1), setup="from __main__ import quick_sort", number=1))

    plot_grafico(x, tempo_des, "Tempo do vetor invertido", "Tempo")
