import time
import matplotlib.pyplot as plt
import numpy as np
import math


def produce_fragment(x, y):
    return math.floor(abs(x)), math.floor(abs(y))


def get_max_and_min(reta1, reta2, reta3):
    x = [reta1[0], reta2[0], reta3[0]]
    y = [reta1[1], reta2[1], reta3[1]]

    min_x = min(map(min, x))
    max_x = max(map(max, x))
    min_y = min(map(min, y))
    max_y = max(map(max, y))

    return [min_x, max_x, min_y, max_y]


def raster(reta_x, reta_y, m, conditional, color, mat):
    x = reta_x[0]
    y = reta_y[0]

    b = y - m * x

    step = 1 if reta_y[1] > reta_y[0] else -1 if conditional == 2 else 1 if reta_x[1] > reta_x[0] else -1

    pixel_x, pixel_y = produce_fragment(x, y)
    mat[int(pixel_y)][int(pixel_x)] = color

    if conditional == 1:
        while x != reta_x[1]:
            x += step
            y = m * x + b
            mat[int(y)][int(x)] = color

    elif conditional == 2:
        while y != reta_y[1]:
            y += step
            x = x if m == 0 else abs((y - b)) / m
            mat[int(y)][int(x)] = color

    return mat


def raster_config(reta1, reta2, reta3, size_x, size_y):
    [min_x, max_x, min_y, max_y] = get_max_and_min(reta1, reta2, reta3)

    delta_max_x = abs(min_x - max_x)
    delta_max_y = abs(min_y - max_y)

    x_scale = 1 if delta_max_x == 0 else int(size_x / delta_max_x)
    y_scale = 1 if delta_max_y == 0 else int(size_y / delta_max_y)

    reta1[0] *= x_scale
    reta1[1] *= y_scale

    reta2[0] *= x_scale
    reta2[1] *= y_scale

    reta3[0] *= x_scale
    reta3[1] *= y_scale

    delta_x1 = abs(reta1[0][1] - reta1[0][0])
    delta_y1 = abs(reta1[1][1] - reta1[1][0])

    delta_x2 = abs(reta2[0][1] - reta2[0][0])
    delta_y2 = abs(reta2[1][1] - reta2[1][0])

    delta_x3 = abs(reta3[0][1] - reta3[0][0])
    delta_y3 = abs(reta3[1][1] - reta3[1][0])

    m1 = 0 if delta_x1 == 0 else delta_y1 / delta_x1
    m2 = 0 if delta_x2 == 0 else delta_y2 / delta_x2
    m3 = 0 if delta_x3 == 0 else delta_y3 / delta_x3

    mat = np.zeros(((delta_max_y * y_scale) + 1, (delta_max_x * x_scale) + 1))

    mat = raster(reta1[0], reta1[1], m1, 1, 5, mat) if delta_x1 >= delta_y1 else raster(reta1[0], reta1[1], m1, 2, 5, mat)
    mat = raster(reta2[0], reta2[1], m2, 1, 4, mat) if delta_x2 >= delta_y2 else raster(reta2[0], reta2[1], m2, 2, 4, mat)
    mat = raster(reta3[0], reta3[1], m3, 1, 3, mat) if delta_x3 >= delta_y3 else raster(reta3[0], reta3[1], m3, 2, 3, mat)

    plot_mat(mat, size_x, size_y)


def plot_mat(matrix, size_x, size_y):
    figure = plt.figure()
    axes = figure.add_subplot(111)
    axes.set_title("{size_x}x{size_y}".format(size_x=size_x, size_y=size_y))

    c_axes = axes.matshow(matrix, interpolation='nearest')
    figure.colorbar(c_axes)


if __name__ == '__main__':
    try:
        reta1 = np.array([[0, 10], [0, 3]])
        reta2 = np.array([[1, 5], [1, 7]])
        reta3 = np.array([[2, 7], [3, 7]])

        raster_config(reta1, reta2, reta3, 40, 30)  #40x30
        raster_config(reta1, reta2, reta3, 800, 600)  #800x600
        raster_config(reta1, reta2, reta3, 1600, 1200)  #1600x1200

        plt.show()

    except ValueError:
        print('Error')
