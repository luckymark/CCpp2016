#ifndef push_boxes_model_h__
#define push_boxes_model_h__

#define MAP_HEIGHT 4
#define MAP_WIDTH 4

typedef enum _element { WALL, PLAYER, BOX, GOAL} element;
typedef enum _condition{ SUCCESS, FAIL, WIN, UNKNOWN} condition;

typedef struct _point {
    int x;
    int y;
} Point;

// PLAYER
typedef struct _player {
    Point coordinate;
} Player;

void set_player(Player *p, int x, int y);

void init_player(Player *p, int x, int y);

// GOAL
typedef struct _goal {
    Point coordinate;
} Goal;

// EXIT
typedef struct _box {
    Point coordinate;
} Box;

void init_box(Box *e, int x, int y);

// WALL
typedef struct _wall {
    int shape[MAP_HEIGHT][MAP_WIDTH];
} Wall;

// MAP
typedef struct _map {
    Player player1;
    Box boxes[MAP_HEIGHT * MAP_WIDTH];
    Goal goals[MAP_HEIGHT * MAP_WIDTH];
    int xsize;
    int ysize;
} Map;

Map *construct_maze(int shape[MAP_HEIGHT][MAP_WIDTH], int px, int py, int ex, int ey);

int has_wall(Map *maze, int x, int y);

element type_of(Map *maze, int x, int y);

condition move_player(Map *maze, int dx, int dy);

#endif
