#include <stdio.h>
#include <stdlib.h>
#include "maze_model.h"



// function for player
void set_player(Player *p, int x, int y) {
    p->coordinate.x = x;
    p->coordinate.y = y;
}

void inner_move_player(Player *p, int dx, int dy) {
    // this function always assumes the input is legal
    p->coordinate.x += dx;
    p->coordinate.y += dy;
}

void init_player(Player *p, int x, int y) {
    set_player(p, x, y);
}

// function for exit
void init_exit(Exit *e, int x, int y) {
    e->coordinate.x = x;
    e->coordinate.y = y;
}

// function for wall
static int inner_has_wall(Wall *wall, int x, int y) {
    return wall->shape[y][x] == 1;
}

// function for maze
Maze *construct_maze(int shape[MAZE_HEIGHT][MAZE_WIDTH], int px, int py, int ex, int ey) {
    Maze *maze = (Maze *) malloc(sizeof(Maze));
    init_player(&maze->player1, px, py);
    init_exit(&maze->exit1, ex, ey);
    for (int i = 0; i < MAZE_HEIGHT; i++) {
        for (int j = 0; j < MAZE_WIDTH; j++) {
            maze->wall1.shape[i][j] = shape[i][j];
        }
    }
    maze->xsize = MAZE_WIDTH;
    maze->ysize = MAZE_HEIGHT;
    return maze;
}

int has_wall(Maze *maze, int x, int y) {
    return inner_has_wall(&maze->wall1, x, y);
}

element type_of(Maze *maze, int x, int y) {
    Player p1 = maze->player1;
    Exit e1 = maze->exit1;
    if (has_wall(maze, x, y)) {
        return WALL;
    } else if (x == p1.coordinate.x && y == p1.coordinate.y) {
        return PLAYER;
    } else if (x == e1.coordinate.x && y == e1.coordinate.y) {
        return EXIT;
    } else {
        return NONE;
    }
}

condition move_player(Maze *maze, int dx, int dy) {
    int new_x = maze->player1.coordinate.x + dx;
    int new_y = maze->player1.coordinate.y + dy;
    printf("newx=%d, newy=%d\n", new_x, new_y);
    switch (type_of(maze, new_x, new_y)) {
        case WALL:
            return FAIL;
        case NONE:
            inner_move_player(&maze->player1, dx, dy);
            return SUCCESS;
        case EXIT:
            return WIN;
        default:
            return UNKNOWN;
    }
}
