#!/usr/bin/python3
""" minimum operations """


from re import I


def minOperations(n):
    """ calculates min ops to result in n H """

    # Check is n is 1 or below
    if n <= 1:
        return 0
    # check if n is prime
    i = isPrime(n)
    if i is True:
        return n

    # if not prime, calculate
    largest = n / i
    next = isPrime(largest)
    if next is True:
        return finish(n, largest)


def finish(n, largest):
    """ return function """
    if n % 2 == 0:
        return int(largest + 2)
    return int(largest + 3)


def isPrime(n):
    """ checks if number is prime """
    for i in range(2, int(n / 2) + 1):
        if (n % i) == 0:
            return i
    return True
