#include "palindrome.h"

/**
 * is_palindrome - checks if palindrome
 * Return: 1 if palindrome else 0
 */
int is_palindrome(unsigned long n)
{
	unsigned int original = n, reversed = 0, remainder;
	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}

	if (original == reversed)
	{
		return (1);
	}
	return (0);
}