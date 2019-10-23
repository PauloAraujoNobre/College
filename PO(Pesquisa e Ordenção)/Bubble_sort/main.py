from random import randint
import timeit
import matplotlib as mpl
import matplotlib.pyplot as plt

def geraLista(tam):
    lista = []
    for i in range(tam):
        n = randint(1,1*tam)
        if n not in lista: lista.append(n)
    return lista

def plot_grafico(x, y, file_name, label, xl = "Entradas", yl = "Saídas"):
    fig = plt.figure(figsize=(10, 8))
    ax = fig.add_subplot(111)
    ax.plot(x,y, label = label)
    ax.legend(bbox_to_anchor=(1, 1),bbox_transform=plt.gcf().transFigure)
    plt.ylabel(yl)
    plt.xlabel(xl)
    fig.savefig(file_name)

def bubble_sort(lista):
    count = 0
    for i in range(len(lista)):
        for j in range(0, len(lista) - i - 1):
            if lista[j] > lista[j+1]:
                count +=1
                lista[j], lista[j+1] = lista[j+1], lista[j]
    return count

x = [10000, 20000, 50000, 100000]
y = []
tempo = []
count = []

for i in range(len(x)):
    y.append(geraLista(x[i]))
    count.append(bubble_sort(y[i]))

for i in range(len(x)):
    tempo.append(timeit.timeit("bubble_sort({})".format(y[i]),setup="from __main__ import bubble_sort", number=1))

plot_grafico(x, tempo, "GraficoTempo.png", "Tempo")
plot_grafico(x, count, "GraficoInteracoes.png", "NumeroInteracoes")
