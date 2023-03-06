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
                if grid[row - 1][i] == 0:
                    perimeter += 1
                #check left
                if grid[row][i - 1] == 0:
                    perimeter += 1
                #check right
                if grid[row][i + 1] == 0:
                    perimeter += 1
                #check below
                if grid[row + 1][i] == 0:
                    perimeter += 1

    return perimeter