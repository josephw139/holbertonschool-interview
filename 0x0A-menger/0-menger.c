#include "menger.h"

/**
 * menger - prints a menger sponge
 * @level: level of sponge to print
 */
void menger(int level)
{

	int i, j, dim, d;

	if (level < 0)
	{
		return;
	}

	for (i = 0, dim = 1; i < level; i++, dim *= 3)
	{
		continue;
	}

	for (i = 0; i < dim; i++)
	{
		for (j = 0; j < dim; j++)
		{
			for (d = dim / 3; d; d /= 3)
			{
				if ((i % (d * 3)) / d == 1 && (j % (d * 3)) / d == 1)
				{
					break;
				}
			}
			printf(d ? " " : "#");
		}
		printf("\n");
	}
}
