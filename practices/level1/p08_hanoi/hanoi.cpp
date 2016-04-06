#include <stdio.h>
void move_hanoi(int from, int to, int blank, int num);

int main() {
    move_hanoi(1, 2, 3, 64);
    return 0;
}

void move_hanoi(int from, int to, int blank, int num) {
    if (num == 1) {
        printf("Moving to %d from %d\n", to, from);
    } else {
        move_hanoi(from, blank, to, num - 1);
        move_hanoi(from, to, blank, 1);
        move_hanoi(blank, to, from, num - 1);
    }
}
