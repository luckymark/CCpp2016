#include<stdio.h>
#include<stdlib.h>
const int WIDTH =100;
void fly(int j);

int main(){
    int j = 1;
    int flag = 0;\
    while(true){
        if(j>WIDTH){
            flag = 1;
        }
        if(!flag){
            j++;
        }else{
            j--;
        }
        if(j<0){
            break;
        }
    }
}

void fly(int j){
    char x = 'a';
    for(int i = 0;i<j;i++){
        printf(" ");
    }
    printf("%c",x);
    system("cls");
}
