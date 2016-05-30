#include <stdio.h>
#include <string.h>

char* encrypt(char string1[]);
char* decrypt(char string2[]);

int main()
{
    char str[100];
    gets(str);
    printf("需要加密的字符为：%s\n",str);
    char encrypt_str[100];
    strcpy(encrypt_str,encrypt(str));
    printf("加密后，字符串为：%s\n",encrypt_str);
    char decrypt_str[100];
    strcpy(decrypt_str,decrypt(encrypt_str));
    printf("解密后，得到原字符串为：%s\n",decrypt_str);
    return 0;
}

char* encrypt(char string1[]){
    for(int i=0;string1[i]!='\0';i++){
        string1[i] = string1[i]  + 4;
    }
    return string1;
}

char* decrypt(char string2[]){
    for(int i=0;i<strlen(string2);i++){
        string2[i] = string2[i] - 4;
    }
    return string2;
}
