#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void add_piles(int grid1[3][3], int grid2[3][3]);
int check_stable(int grid1[3][3]);
void topple(int grid1[3][3]);
void copy_grid(int grid1[3][3], int copy[3][3]);

static void print_grid(int grid[3][3]);

#endif
