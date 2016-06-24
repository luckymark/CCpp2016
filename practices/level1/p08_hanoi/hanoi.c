#include <stdio.h>

void brain(int n, char a, char b, char c);

int main(void) {
    char a = 'A', b = 'B', c = 'C';
    int piles = 3;

    brain(piles, a, b, c);
    return 0;
}

void brain(int n, char a, char b, char c) {
    if (n == 1) {
        printf("%c -> %c\n", a, c);

    }
    else {
        brain(n - 1, a, c, b);//上面n-1层A-B
        printf("%c -> %c\n", a, c);
        brain(n - 1, b, a, c);//上面n-1层B-C
    }
}
