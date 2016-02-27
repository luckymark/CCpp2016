#include <stdio.h>

void move_hanoi(int from, int to, int empty, int num) {
    if (num == 1) {
        printf("Moving to %d from %d\n", to, from);
    } else {
        move_hanoi(from, empty, to, num - 1);
        move_hanoi(from, to, empty, 1);
        move_hanoi(empty, to, from, num - 1);
    }
}

int main(int argc, char const *argv[]) {
    move_hanoi(1, 2, 3, 10);
    return 0;
}
