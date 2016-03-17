#include <stdio.h>
#include <stdlib.h>
#include "maze_model.h"
#include "maze_view.h"
#define PSYMBOL '@'
#define ESYMBOL 'V'
#define WSYMBOL '#'
#define EMPTY ' '

int clear_display(void) {
    system("clear");
    return 0;
}

int display_maze(Maze *maze) {
    clear_display();
    for (int y = 0; y < MAZE_WIDTH; y++) {
        for (int x = 0; x < MAZE_HEIGHT; x++) {
            switch (type_of(maze, x, y)) {
                case WALL:
                    putchar(WSYMBOL);
                    break;
                case PLAYER:
                    putchar(PSYMBOL);
                    break;
                case EXIT:
                    putchar(ESYMBOL);
                    break;
                default: putchar(EMPTY);
            }
        }
        putchar('\n');
    }
    return 0;
}

int display_win_page() {
    clear_display();
    printf("YOU WON!\n");
    return 0;
}
