#include "push_boxes_model.h"

void set_player(Player *p, int x, int y);
void init_player(Player *p, int x, int y);
void init_box(Box *e, int x, int y);
Map *construct_maze(int shape[MAP_HEIGHT][MAP_WIDTH], int px, int py, int ex, int ey);
int has_wall(Map *maze, int x, int y);
element type_of(Map *maze, int x, int y);
condition move_player(Map *maze, int dx, int dy);
