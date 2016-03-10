#include<cstdio>
#define MAX 64
void transform(int n,char from,char to,char via) {
    if (n == 1) {
        printf("%c --> %c\n", from, to);
    } else {
        transform(n - 1, from, via, to);
        printf("%c --> %c\n", from, to);
        transform(n - 1, via, to, from);
    }
}
int main() {
    transform(MAX, 'A', 'C', 'B');
    return 0;
}
