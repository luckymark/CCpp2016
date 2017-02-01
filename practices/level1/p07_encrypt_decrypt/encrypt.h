#ifndef _ENCRYPT_H

#define _ENCRYPT_H

#include <stdio.h>
#include <string.h>

#define CHARSET_SIZE 26

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
    key %= CHARSET_SIZE;
    for(int i = 0;i < len; ++i){
        if(input[i] <='z' && input[i] >='a'){
            int offset = input[i] - 'a';
            input[i] = 'A' + (offset + key) % CHARSET_SIZE;
        }else{
            int offset = input[i] - 'A';
            input[i] = 'a' + (offset + key) % CHARSET_SIZE;
        }
    }
    return (int)key;
}

#endif // _ENCRYPT_H
