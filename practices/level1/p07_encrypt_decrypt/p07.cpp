#include "encrypt.h"
#include "decrypt.h"

#include <stdio.h>
#define MAX_STRING_LEN 10000

char buf[MAX_STRING_LEN];
int main(){
    while(1){
        printf("Please input your Choose\n1) ENCRYPT\n2) DECRYPT\n");
        scanf("%s", buf); // Deal with more input infomation
        char opt = buf[0];
        if(opt == '1'){
            printf("Please Input a string\n");
            scanf("%s", buf);
            int key = encrypt(buf);
            printf("Your key = %d\n", key);
            printCryptString(buf);
        }else if(opt == '2'){
            int key;
            printf("Please Input a string\n");
            scanf("%s", buf);
            printf("Please Input your Key\n");
            scanf("%d", &key);
            decrypt(buf, key);
            printf("%s\n", buf);
        }else{
            printf("TYPE ERROR\n");
            continue;
            // Invaid Option Input
        }

    }


}
