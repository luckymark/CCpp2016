#ifndef _DECRYPT_H

#define _DECRYPT_H

#include <string.h>

void decrypt(char input[],int key){
    int len = strlen(input);
    for(int i = 0; i < len; ++i){
        input[i] ^= (char)key;
    }
}

#endif // _DECRYPT_H
