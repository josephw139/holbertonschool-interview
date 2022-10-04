#include "sandpiles.h"
/**
 * main - Prints out the following text
 *
 * Return: 0
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int stable = 0;

	// Add the initial grids together
	add_piles(grid1, grid2);

	while (stable == 0)
	{
		// Check if stable
		stable = check_stable(grid1);

		// if stable, return
		if (stable == 1)
		{
			return;
		}

		// If not stable, print new pile, then topple
		printf("=\n");
		print_grid(grid1);


		// topple
		topple(grid1);
	}
}


void add_piles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	return;
}

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

void topple(int grid1[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				grid1[i][j] -= 4;

				// check above
				if (i > 0)
				{
					grid1[i - 1][j] += 1;
				}

				// check right
				if (j < 2)
				{
					grid1[i][j + 1] += 1;
				}

				// check below
				if (i < 2)
				{
					grid1[i + 1][j] += 1;
				}

				// check left
				if (j > 0)
				{
					grid1[i][j - 1] += 1;
				}

			}
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