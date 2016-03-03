#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define N 78

int main(void)
{
    int i,j;
    char mark = 'a';
    for(i=0;i<=N;i++){
        for(j=0;j<=i;j++){
            printf("%c",mark);
            system("cls");
            }
        }

    for(i=0;i<=N;i++){
        for(j=0;j<=N-i;j++){
            printf("%c",mark);
            system("cls");
        }
    }
    return 0;
}