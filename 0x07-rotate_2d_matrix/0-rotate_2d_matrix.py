#!/usr/bin/python3
"""
0x07 - Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ Do a barrel roll """
    old_matrix = [row[:] for row in matrix]

    for row in range(len(matrix)):
        col = len(matrix) - 1
        for num in range(len(matrix[0])):
            matrix[row][num] = old_matrix[col][row]
            col -= 1
