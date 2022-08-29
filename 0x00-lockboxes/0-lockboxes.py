#!/usr/bin/python3
""" Task 0 - method that determines if all the boxes can be opened.
"""


def canUnlockAll(boxes):
    """ lockboxes """
    keys = []
    flag = 0

    while (flag < 2):
        for i in boxes[0]:
            keys.append(i)

        for i in range(1, len(boxes) - 1):
            if i in keys:
                for j in boxes[i]:
                    keys.append(j)
        flag += 1

    for i in range(1, len(boxes) - 1):
        if i not in keys:
            return False

    return True
