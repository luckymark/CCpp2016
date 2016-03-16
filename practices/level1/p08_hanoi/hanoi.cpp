#include <stdio.h>

void move_hanoi(int go, int to, int empty, int num) {
    if (num == 1) {
        
    } else {
    	printf("%d-->%d\n", go, to);
        move_hanoi(go, empty, to, num - 1);
        move_hanoi(empty, to, go, num - 1);
    }
}

int main() {
    move_hanoi(1, 2, 3, 64);
    return 0;
}
