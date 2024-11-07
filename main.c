#include <stdio.h>

#include "main.h"

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

}

void initalize(int grid[SIZE][SIZE])
{
  set_alive(grid,15,15);
  set_alive(grid,15,16);
  set_alive(grid,15,17);
}

void set_alive(int grid[SIZE][SIZE], int i, int j)
{
  grid[i][j] = 1;
}

void set_dead(int grid[SIZE][SIZE], int i, int j)
{
  grid[i][j] = 0;
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

int main( int argc, char **argv) {
  if ( argc <= 1 ) {
    printf("Usage: %s [number of generation to compute]\n", argv[0]);
    return 1;
  }

  int gridA[SIZE][SIZE] = {0};
  int gridB[SIZE][SIZE] = {0};
  initalize(gridA);
  render_grid(gridA);
  printf("%d\n", compute_neighbors(gridA,15,15));

  return 0;
}
