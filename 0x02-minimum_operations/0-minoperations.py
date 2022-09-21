#!/usr/bin/python3
""" minimum operations """


def minOperations(n):
    """ calculates min ops to result in n H """

    if n <= 1:
        return 0

    file = ['H']
    count = len(file)
    if isPrime(n):
        return n


def isPrime(n):
    """ checks if number is prime """
    for i in range(2, int(n/2) + 1):
        if (n % i) == 0:
            return False
    return True
