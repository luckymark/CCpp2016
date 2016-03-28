#include <stdio.h>
#include "maze_view.h"
#include "maze_model.h"

int main(int argc, char const *argv[]) {
    int wall[MAZE_HEIGHT][MAZE_WIDTH] = {
        {1, 0, 1, 1},
        {1, 0, 0, 1},
        {1, 1, 0, 1},
        {1, 1, 0, 1}
    };
    Maze *maze = construct_maze(wall, 1, 0, 2, 3);
    while (1) {
        display_maze(maze);
        char input = getchar();
        int dx = 0, dy = 0;
        switch (input) {
            case 'w':
                dy = -1;
                break;
            case 's':
                dy = 1;
                break;
            case 'a':
                dx = -1;
                break;
            case 'd':
                dx = 1;
                break;
            case '\n':
                break;
            default:
                printf("An Error Occured");
        }
        condition cond = move_player(maze, dx, dy);
        if (cond == WIN) {
            display_win_page();
            break;
        }
    }
    return 0;
}
