#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80

int main(int argc, char const *argv[]) {
    for (size_t i = 0; i < 2 * WIDTH; i++) {
        int space = WIDTH - abs(WIDTH - (int) i);
        for (size_t j = 0; j < space; j++) {
            printf(" ");
        }
        printf("K");
        system("cls");
    }
    return 0;
}
