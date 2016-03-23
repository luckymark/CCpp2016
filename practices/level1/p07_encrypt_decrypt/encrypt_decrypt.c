#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void encrypt(int len);
void decrypt(int len);
char s[10000];
int main()
{
    int len;
    int judge;
    printf("请输入你需要的功能:1代表加密，2代表解密\n");
    scanf("%d",&judge);
    if(judge==1)
    {
        printf("请输入你需要加密的文字:");
        scanf("%s",&s);
        len=strlen(s);
        encrypt(len);
        printf("加密后的密文为:");
    }
    if(judge==2)
    {
        printf("请输入你要解密的密文:");
        scanf("%s",&s);
        len=strlen(s);
        decrypt(len);
        printf("解密后的密文为:");
    }
    puts(s);
    return 0;
}
void encrypt(int len)
{
    int encryption;
    for(int i=0;i<len;i++)
    {
        encryption=(i*i)%7;//生成加密用数
        s[i]+=encryption;//加密
    }
}
void decrypt(int len)
{
    int decryption;
    for(int i=0;i<len;i++)
    {
        decryption=(i*i)%7;//生成解密用数
        s[i]-=decryption;//解密
    }
}
