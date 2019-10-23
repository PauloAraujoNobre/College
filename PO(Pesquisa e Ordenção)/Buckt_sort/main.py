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


def merge(lista_esq, lista_dir):
    final = []
    while lista_esq or lista_dir:

        if len(lista_esq) and len(lista_dir):
            if lista_esq[0] < lista_dir[0]:
                final.append(lista_esq.pop(0))

            else:
                final.append(lista_dir.pop(0))

        if not len(lista_esq):
            if len(lista_dir):
                final.append(lista_dir.pop(0))

        if not len(lista_dir):
            if len(lista_esq):
                final.append(lista_esq.pop(0))

    return final

def merge_sort(lista):

     if len(lista) < 2:
         return lista
     mid = len(lista) / 2
     return merge(merge_sort(lista[:mid]), merge_sort(lista[mid:]))


def bucket_sort(lista):
    maior = max(lista)
    tam = len(lista)
    size = maior/tam

    baldes = [[] for k in range(tam)]

    for i in range(tam):
        j = int(lista[i]/size)
        if j != tam:
            baldes[j].append(lista[i])
        else:
            baldes[tam - 1].append(lista[i])

    for i in range(tam):
        merge_sort(baldes[i])

    lista_final = []

    for i in range(tam):
        lista_final = lista_final + baldes[i]

    return lista_final

if __name__ == '__main__':
    x = [10000, 20000, 40000, 50000, 100000, 200000]
    y_des = []
    tempo_des = []

    for i in range(len(x)):
        y_des.append(geraLista(x[i]))

    for i in range(len(x)):
        tempo_des.append(timeit.timeit("bucket_sort({})".format(y_des[i]), setup="from __main__ import bucket_sort", number=1))
        print(i)

    plot_grafico(x, tempo_des, "Tempo do vetor aleatório", "Tempo")
