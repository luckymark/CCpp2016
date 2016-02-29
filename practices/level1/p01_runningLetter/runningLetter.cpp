#include<stdio.h>
#include<stdlib.h>
const int width =100;
void fly(int j){
    char x = 'a';
    for(int i = 0;i<j;i++){
        printf(" ");
    }
    printf("%c",x);
    system("cls");
}
int main(){
    int j = 1;
    for(;j<width;j++){
        fly(j);
    }
    for(;j>0;j--){
        fly(j);
    }
}
