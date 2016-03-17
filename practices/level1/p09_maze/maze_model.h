#ifndef _MAZE_MODEL_H
#define _MAZE_MODEL_H

#define MAZE_HEIGHT 4
#define MAZE_WIDTH 4

typedef enum _element { WALL, PLAYER, EXIT, NONE} element;
typedef enum _condition{ SUCCESS, FAIL, WIN, UNKNOWN} condition;

typedef struct _point {
    int x;
    int y;
} Point;

// PLAYER
typedef struct _player {
    Point coordinate;
    char symbol;
} Player;

void set_player(Player *p, int x, int y);

void init_player(Player *p, int x, int y);

// EXIT
typedef struct _exit {
    Point coordinate;
    char symbol;
} Exit;

void init_exit(Exit *e, int x, int y);

// WALL
typedef struct _wall {
    int shape[MAZE_HEIGHT][MAZE_WIDTH];
    char symbol;
} Wall;

// MAZE
typedef struct _maze {
    Player player1;
    Exit exit1;
    Wall wall1;
    int xsize;
    int ysize;
} Maze;

Maze *construct_maze(int shape[MAZE_HEIGHT][MAZE_WIDTH], int px, int py, int ex, int ey);

int has_wall(Maze *maze, int x, int y);

element type_of(Maze *maze, int x, int y);

condition move_player(Maze *maze, int dx, int dy);

#endif
