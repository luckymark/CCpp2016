//
//  main.c
//  encrypt
//
//  Created by 陈浩贤 on 16/3/10.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>
#define CODELENGTH 30

char code[CODELENGTH];
void encryption();
void decryption();
int decision();

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("please enter your code\n");
    scanf("%s",code);
    
    encryption();
    printf("your code after encrypted:%s\n",code);
    
    printf("do you want to encry your code? y/n \n");
    if(decision()==1) {
        decryption();
        printf("your code after decryption:%s\n",code);
    }else{
        printf("欢迎再次使用本加密系统\n");
    }
    
    
    return 0;
}

void encryption()
{
    for (int i=0;i<=sizeof(code); i++) {

        code[i]=code[i]+20;
        
    }
}

void decryption(){
    for (int i=0; i<=sizeof(code);i++) {
        code[i]=code[i]-20;
    }
}
int decision(){
    char decide;
    scanf("%s",&decide);
    
    if (decide=='y'||decide=='Y') {
        return 1;
    }else{
        return 0;
    }
}