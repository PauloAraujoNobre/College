from random import randint, shuffle
import timeit
import matplotlib as mpl
import matplotlib.pyplot as plt

def geraLista(tam):
    lista = list(range(1, tam+1))
    shuffle(lista)
    return lista

def plot_grafico(x, y, z, file_name, label1, label2, xl = "Entradas", yl = "Saídas"):
    fig = plt.figure(figsize=(10, 8))
    ax = fig.add_subplot(111)
    ax.plot(x, y, label= label1)
    ax.plot(x, z, label= label2)
    ax.legend(bbox_to_anchor=(1, 1),bbox_transform=plt.gcf().transFigure)
    plt.ylabel(yl)
    plt.xlabel(xl)

    fig.savefig(file_name)

def insertion_sort(lista):
    count = 0
    for i in range(1, len(lista)):
        aux = lista[i]
        j = i - 1
        while j >= 0 and aux < lista[j]:
            count += 1
            lista[j + 1] = lista[j]
            j -= 1
        lista[j + 1] = aux
        count += 1
    counts.append(count)
    return count

x = [10000, 20000, 50000, 100000]
y_ran = []
y_des = []
tempo_ran = []
count_ran = []
tempo_des = []
count_des = []

counts = []
counts_ran = []
counts_des = []
for i in range(len(x)):
    y_ran.append(geraLista(x[i]))

    aux = list(range(1, x[i]+1))
    aux.reverse()
    y_des.append(aux)

for i in range(len(x)):
    tempo_ran.append(timeit.timeit("insertion_sort({})".format(y_ran[i]), setup="from __main__ import insertion_sort", number=1))
    tempo_des.append(timeit.timeit("insertion_sort({})".format(y_des[i]), setup="from __main__ import insertion_sort", number=1))

for i in range(len(counts)):
    if i % 2 == 0:
        count_ran.append(counts[i])
    if i % 2 != 0:
        count_des.append(counts[i])

plot_grafico(x, tempo_ran, tempo_des, "GraficoTempo.png", "Tempo Embaralhado", "Tempo Invertido")
plot_grafico(x, count_ran, count_des, "GraficoInteracoes.png", "Numero de Interacoes Embaralhado", "Numero de Interacoes Invertido")
