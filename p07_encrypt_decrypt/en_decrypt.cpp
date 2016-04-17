#include <stdio.h>

int encrypt(int move);
int decrypt(int move);

int main(void) {
    printf("这是一个简单的凯撒移位加解密程序。\n");
    printf("1:加密\n");
    printf("2:解密\n");

    int ch,move;

    scanf(" %1d",&ch);
    switch(ch){
        case 1:
            printf("移位数：\n");
            scanf(" %1d",&move);
            encrypt(move);
            break;
        case 2:
            printf("移位数：");
            scanf(" %d",&move);
            decrypt(move);
            break;
    }
    return 0;
}

int encrypt(int move) {
    int count=0;
    char p[100];
    char q[100];

    printf("请输入想加密的字符串。\n");
    while ((p[count] =(char)getchar()) != '\n')
    {
        count++;
    };
    for(int i=0;i<count;i++){
        if(int(p[i])>=65 && int(p[i])<=(90-move) ) {
            q[i]=char(p[i]+move);
            printf("%c",q[i]);
        }
        else if(int(p[i])>(90-move)) {
            q[i]=char(p[i]+move-26);
            printf("%c",q[i]);
        }
    }
    return 0;
}

int decrypt(int move) {
    int count = 0;
    char p[100];
    char q[100];

    printf("请输入想解密的字符串。\n");
    while ((p[count] = (char) getchar()) != '\n') {
        count++;
    };
    for (int i = 0; i < count; i++) {
        if (int(p[i]) >= (65 + move) && int(p[i]) <= 90) {
            q[i] = char(p[i] - move);
            printf("%c", q[i]);
        }
        else if (int(p[i]) < 90) {
            q[i] = char(p[i] - move + 26);
            printf("%c", q[i]);
        }
    }
    return 0;
}