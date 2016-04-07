#include<stdio.h>
void hanoi(int n,char from,char by,char to);
void move(char from,char to);
int main(){
    int n=2;
    hanoi(n,'A','B','C');
    return 0;
}

void hanoi(int n,char from,char by,char to){
    if(1==n){
    	move(from,to);
	return;
    }
    hanoi(n-1,from,to,by);
    move(from,to);
    hanoi(n-1,by,from,to);
    }
void move(char from,char to){
    printf("%c->%c \n",from,to);
}
