#include <stdio.h>
#include <windows.h>
#define N 78

int main(void)
{
    char mark = 'a';
    for(int i=0;i<=N;i++){
        for(int j=0;j<=i;j++){
            printf("%c",mark);
            system("cls");
            }
        }

    for(int i=0;i<=N;i++){
        for(int j=0;j<=N-i;j++){
            printf("%c",mark);
            system("cls");
        }
    }
    return 0;
}