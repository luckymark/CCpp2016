// Created by Zyx on 2016/3/10.
// 思考过程：
// 两层：A-B A-C B-C
// 三层：上面两层看成一层（A-C A-B C-B），然后A-C，之后两层从B-C。
// 四层：上面三层看成一层，然后全部移到B，最后最下面移到C。
// 简单地说，就是将最上面的所有层移到B。
#include <stdio.h>

void moving(char a,char b,char c);
void brain(int n,char a,char b,char c);

int main(void){
    char a='A',b='B',c='C';
    int piles =64;

    brain(piles,a,b,c);
    return 0;
}

void brain(int n,char a,char b,char c){
    if (n ==3){
        moving(a,b,c);

    }
    else {
        brain(n-1,a,c,b);//上面n-1层A-B
        printf("%c -> %c\n",a,c);
        brain(n-1,b,a,c);//上面n-1层B-C
    }
}

//本函数完成两层从A-C的归位
void moving(char a,char b,char c){
    printf("%c -> %c\n",a,b);
    printf("%c -> %c\n",a,c);
    printf("%c -> %c\n",b,c);
}