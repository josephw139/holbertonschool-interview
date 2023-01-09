#!/usr/bin/python3
"""
0-rain
"""

def rain(walls):
    """ Calculates how many square units of water retained """
    sum = 0
    leftWall = 0
    rightWall = 0
    mult = 0
    lower = 0
    for i in range(len(walls)):
        if walls[i] != 0 and leftWall == 0:
           leftWall = walls[i]
        if walls[i] != 0 and leftWall != 0 and mult != 0:
            rightWall = walls[i]
        if walls[i] == 0 and leftWall != 0:
            mult += 1
        if leftWall != 0 and rightWall != 0:
            if leftWall > rightWall:
                lower = rightWall
            else:
                lower = leftWall
            sum += lower * mult
            leftWall = rightWall
            rightWall = 0
            mult = 0

    return sum
