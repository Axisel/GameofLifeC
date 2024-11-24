#include <stdio.h>

#include "main.h"

#include <stdlib.h>
#include <unistd.h>

int is_valid(int grind[SIZE][SIZE], int i, int j)
{
  return i >= 0 && i < SIZE && j >= 0 && j < SIZE;
}

int compute_neighbors(int grid[SIZE][SIZE], int i, int j)
{
  int count = 0;

  for (int k = i-1; k <= i+1; k++)
  {
    for (int l = j-1; l <= j+1; l++)
    {
      if (k == i && l == j)
        continue;
      if (is_valid(grid, k, l))
          count += grid[k][l];
    }
  }

  return count;
}

void initalize(int grid[SIZE][SIZE])
{
  set_alive(grid,15,15);
  set_alive(grid,15,16);
  set_alive(grid,15,17);
  set_alive(grid,14,17);
  set_alive(grid,13,16);
}

void set_alive(int grid[SIZE][SIZE], int i, int j)
{
  grid[i][j] = 1;
}

void render_grid(int grid[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (grid[i][j] == 1)
        printf("*");
      else
        printf(".");
    }
    printf("\n");
  }
}

void copy_array(int grid[SIZE][SIZE], int grid2[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      grid2[i][j] = grid[i][j];
    }
  }
}

void update_cell(int gridA[SIZE][SIZE], int gridB[SIZE][SIZE], int i, int j)
{
  int alive_neighbors = compute_neighbors(gridA, i, j);
  gridB[i][j] = alive_neighbors == 3 || (gridA[i][j] == 1 && alive_neighbors == 2);
}

void launch_life(int gridA[SIZE][SIZE], int gridB[SIZE][SIZE], int generation_count)
{
  int current_generation = 0;
  for (current_generation; current_generation < generation_count; current_generation++)
  {
    printf("Generation : %d\n", current_generation);
    render_grid(gridA);
    for (int i = 0; i < SIZE; i++)
    {
      for (int j = 0; j < SIZE; j++)
      {
        update_cell(gridA, gridB, i, j);
      }
    }
    copy_array(gridB, gridA);
    usleep(500*1000);
    printf("\x1b[31A\r");
  }

}

int main(int argc, char **argv)
{
  if ( argc <= 1 )
  {
    printf("Usage: %s [number of generation to compute]\n", argv[0]);
    return 1;
  }

  int gridA[SIZE][SIZE] = {0};
  int gridB[SIZE][SIZE] = {0};
  initalize(gridA);
  launch_life(gridA, gridB, atoi(argv[1]));

  return 0;
}
