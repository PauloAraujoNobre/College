from random import randint, shuffle
import timeit
import matplotlib as mpl
import matplotlib.pyplot as plt
import sys

sys.setrecursionlimit(15000)

def geraLista(tam):
    lista = list(range(0, tam+1))
    shuffle(lista)
    return lista

def plot_grafico(x, y, file_name, label1, xl = "Entradas", yl = "Saídas"):
    fig = plt.figure(figsize=(10, 8))
    ax = fig.add_subplot(111)
    ax.plot(x, y, label= label1)
    ax.legend(bbox_to_anchor=(1, 1),bbox_transform=plt.gcf().transFigure)
    plt.ylabel(yl)
    plt.xlabel(xl)

    fig.savefig(file_name)

def merge(esq_lista, dir_lista):
    final = []
    while esq_lista or dir_lista:

        if len(esq_lista) and len(dir_lista):
            if esq_lista[0] < dir_lista[0]:
                final.append(esq_lista.pop(0))
            else:
                final.append(dir_lista.pop(0))

        if not len(esq_lista):
            if len(dir_lista): final.append(dir_lista.pop(0))

        if not len(dir_lista):
            if len(esq_lista): final.append(esq_lista.pop(0))

    return final

def merge_sort(lista):
        if len(lista) < 2:
            return lista
        meio = int(len(lista) / 2)
        return merge(merge_sort(lista[:meio]), merge_sort(lista[meio:]))

if __name__ == '__main__':
    x = [100000, 200000, 400000, 500000, 1000000, 2000000]
    y_des = []
    tempo_des = []

    for i in range(len(x)):
        y_des.append(geraLista(x[i]))

    for i in range(len(x)):
        tempo_des.append(timeit.timeit("merge_sort({})".format(y_des[i]), setup="from __main__ import merge_sort", number=1))
        print(i)

    plot_grafico(x, tempo_des, "Tempo do vetor aleatório", "Tempo")
