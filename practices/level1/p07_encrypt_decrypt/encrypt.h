#ifndef _ENCRYPT_H

#define _ENCRYPT_H

#include <stdio.h>
#include <string.h>

int encrypt(char input[])
{
    /*
    return decrypt key
    */
    int len = strlen(input);
    int key = 0;
    for(int i = 0; i < len; ++i){
        key += input[i];
    }
    key %= 26;
    for(int i=0;i<len;++i){
        if(input[i]<='z' && input[i] >='a'){
            int offset = input[i] - 'a';

        }
        input[i] = key;
    }
    return (int)key;
}

void printCryptString(char input[]){
    int len = strlen(input);
    for(int i = 0; i < len; ++i){
        printf("%02d",input[i]);
    }
    printf("\n");
}

#endif // _ENCRYPT_H
