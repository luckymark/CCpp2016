#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void Buildkey(char* key,int keylen);
void Encrypt(void);
void Decrypt();
int main()
{
    Encrypt();
    Decrypt();
    return 0;
}

void Buildkey(char* key,int keylen){
    srand((int)time(NULL));
    int i;
    for(i=0;i<10;i++){
        key[i]=rand()%26+'a';
    }
    printf("The key has been built as: %s\n",key);
}

void Encrypt(void){
    int i=0;
    char c;
    char key[10]={0};
    Buildkey(key,10);
    printf("input the string to encrypt: ");
    c=getchar();
    do{
        printf("%d ",(int)c^key[i%10]);
        i++;
    }while((c=getchar())!='\n');
}

void Decrypt(void){
    char key[10];
    int i=0;
    int a;
    printf("\ninput your key (10 letters): ");
    scanf("%s",key);
    printf("input the string to decrypt (input '-1' to end the inputing): ");
    for(i=0;scanf("%d",&a)==1&&a!=-1;i++){
        printf("%c",(char)a^key[i%10]);
    }
}
