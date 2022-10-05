#include "sandpiles.h"
/**
 * sandpiles_sum - Adds and topples two grids
 * @grid1: first grid
 * @grid2: second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int stable = 0, i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	while (stable == 0)
	{
		stable = check_stable(grid1);

		if (stable == 1)
		{
			return;
		}

		printf("=\n");
		print_grid(grid1);

		topple(grid1);
	}
}

/**
 * check_stable - checks to see if grid1 needs to be toppled
 * @grid1: the grid to check
 * Return: 1 if stable, 0 if not
 */
int check_stable(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
 * topple - topples grid1
 * @grid1: grid to topple
 */
void topple(int grid1[3][3])
{
	int i, j;
	int copy[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};
	copy_grid(grid1, copy);

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (copy[i][j] > 3)
			{
				grid1[i][j] -= 4;

				if (i > 0)
				{
					grid1[i - 1][j] += 1;
				}
				if (j < 2)
				{
					grid1[i][j + 1] += 1;
				}
				if (i < 2)
				{
					grid1[i + 1][j] += 1;
				}
				if (j > 0)
				{
					grid1[i][j - 1] += 1;
				}

			}
		}
	}
}

/**
 * copy_grid - copies grid1 to reference original values
 * @grid1: orignal grid
 * @copy: reference grid
 */
void copy_grid(int grid1[3][3], int copy[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			copy[i][j] = grid1[i][j];
		}
	}

}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
