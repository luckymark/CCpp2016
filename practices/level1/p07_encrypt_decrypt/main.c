#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrept();
void decrypt();
int main()
{
    char a[50];
    gets(a);
    encrypt(a);
    printf("加密完成，解密请按1\n");
    int input;
    scanf("%d",&input);
    if(input==1)
    {
        decrypt(a);
        printf("解密完成\n");
    }
    return 0;
}
void encrypt(char a[50])
{
    int i=0,len=strlen(a);
    for(i=0;i<=len-1;i++)
    {
        a[i]+=1;
    }
}
void decrypt(char a[50])
{
    int i=0,len=strlen(a);
    for(i=0;i<=len-1;i++)
    {
        a[i]-=1;
    }
}
