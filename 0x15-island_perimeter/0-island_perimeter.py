#!/usr/bin/python3
"""
Calculates perimeter around binary islands
"""


def island_perimeter(grid):
    """Calculates perimeter around binary islands"""
    perimeter = 0
    for row in range(len(grid)):
        for i in range(len(grid[0])):
            if grid[row][i] == 1:
                # check above
                if row == 0:
                    perimeter += 1
                elif grid[row - 1][i] == 0:
                    perimeter += 1
                # check left
                if i == 0:
                    perimeter += 1
                elif grid[row][i - 1] == 0:
                    perimeter += 1
                # check right
                if i == len(grid[0]) - 1:
                    perimeter += 1
                elif grid[row][i + 1] == 0:
                    perimeter += 1
                # check below
                if row == len(grid) - 1:
                    perimeter += 1
                elif grid[row + 1][i] == 0:
                    perimeter += 1

    return perimeter
