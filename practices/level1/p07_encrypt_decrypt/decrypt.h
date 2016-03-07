#ifndef _DECRYPT_H

#define _DECRYPT_H

#include <string.h>

#define CHARSET_SIZE 26

void decrypt(char input[],int key){
    int len = strlen(input);
    for(int i = 0; i < len; ++i){
        if(input[i] <= 'z' && input[i] >= 'a'){
        	input[i] = 'A' + (input[i] - 'a' + CHARSET_SIZE - key) % CHARSET_SIZE;
        }else{
        	input[i] = 'a' + (input[i] - 'A' + CHARSET_SIZE - key) % CHARSET_SIZE;
        }
    }
}

#endif // _DECRYPT_H
