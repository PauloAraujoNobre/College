from random import randint, shuffle
import timeit
import matplotlib as mpl
import matplotlib.pyplot as plt

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


def heapify(lista, n, i):
    largest = i
    esq = 2 * i + 1
    dir = 2 * i + 2

    if esq < n and lista[i] < lista[esq]:
        largest = esq

    if dir < n and lista[largest] < lista[dir]:
        largest = dir

    if largest != i:
        lista[i], lista[largest] = lista[largest], lista[i]  # swap

        heapify(lista, n, largest)



def heap_sort(lista):
    n = len(lista)
    for i in range(n, -1, -1):
        heapify(lista, n, i)
    for i in range(n - 1, 0, -1):
        lista[i], lista[0] = lista[0], lista[i]  # swap
        heapify(lista, i, 0)

if __name__ == '__main__':
    x = [100000, 200000, 400000, 500000, 1000000, 2000000]
    y_des = []
    tempo_des = []

    for i in range(len(x)):
        y_des.append(geraLista(x[i]))

    for i in range(len(x)):
        tempo_des.append(timeit.timeit("heap_sort({})".format(y_des[i]), setup="from __main__ import heap_sort", number=1))
        print(i)

    plot_grafico(x, tempo_des, "Tempo do vetor aleatório", "Tempo")
