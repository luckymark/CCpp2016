#include<cstdio>
#define MAX 64
void hanoi(int n,char from='A',char to='C',char via='B');
void print(char from,char to);
int main() {
    hanoi(MAX);
    return 0;
}
void print(char from,char to) {
    printf("%c --> %c\n", from, to);
}
void hanoi(int n,char from,char to,char via) {
    if (n == 1) {
        print(from, to);
    } else {
        hanoi(n - 1, from, via, to);
        print(from, to);
        hanoi(n - 1, via, to, from);
    }
}
