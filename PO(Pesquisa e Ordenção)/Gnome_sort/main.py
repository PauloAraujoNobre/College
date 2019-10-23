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


def gnome_sort(lista, tam):
    index = 0
    while index < tam:
        if index == 0:
            index = index + 1
        if lista[index] >= lista[index - 1]:
            index = index + 1
        else:
            lista[index], lista[index - 1] = lista[index - 1], lista[index]
            index = index - 1

    return lista

if __name__ == '__main__':
    x = [10000, 20000, 40000, 50000, 100000]
    y_des = []
    tempo_des = []

    for i in range(len(x)):
        y_des.append(geraLista(x[i]))

    for i in range(len(x)):
        tempo_des.append(timeit.timeit("gnome_sort({},{})".format(y_des[i], len(y_des[i])), setup="from __main__ import gnome_sort", number=1))
        print(i)

    plot_grafico(x, tempo_des, "Tempo do vetor aleatório", "Tempo")
