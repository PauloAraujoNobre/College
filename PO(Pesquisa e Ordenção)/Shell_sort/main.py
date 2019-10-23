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


def shellSort(lista):
    n = len(lista)
    aux = int(n / 2)
    while aux > 0:
        for i in range(aux, n):
            temp = lista[i]
            j = i
            while j >= aux and lista[j - aux] > temp:
                lista[j] = lista[j - aux]
                j = j - aux
            lista[j] = temp
        aux = int(aux / 2)

if __name__ == '__main__':
    x = [100000, 200000, 400000, 500000, 1000000, 2000000]
    y_des = []
    tempo_des = []

    for i in range(len(x)):
        y_des.append(geraLista(x[i]))

    for i in range(len(x)):
        tempo_des.append(timeit.timeit("shellSort({})".format(y_des[i]), setup="from __main__ import shellSort", number=1))
        print(i)

    plot_grafico(x, tempo_des, "Tempo do vetor aleatório", "Tempo")
