#ifndef MAIN_H
#define MAIN_H

#define SIZE 30

void render_grid(int grid[SIZE][SIZE]);

void set_dead(int grid[SIZE][SIZE], int i, int j);

void set_alive(int grid[SIZE][SIZE], int i, int j);

void initalize(int grid[SIZE][SIZE]);

#endif //MAIN_H
