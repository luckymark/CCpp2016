#include<cstdio>
#define MAX 64
void hanoi(int n,char from='A',char to='C',char via='B') {
    if (n == 1) {
        printf("%c --> %c\n", from, to);
    } else {
        hanoi(n - 1, from, via, to);
        printf("%c --> %c\n", from, to);
        hanoi(n - 1, via, to, from);
    }
}
int main() {
    hanoi(MAX);
    return 0;
}
