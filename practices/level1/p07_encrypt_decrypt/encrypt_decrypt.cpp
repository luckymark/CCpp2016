#include<stdio.h>
int main(){
    char message[100]={0};
    char word[100]={0};
    printf("your message: ");
    scanf("%s",message);
    printf("your key: (length>message)");
    scanf("%s",word);
    for(int i = 0;message[i]!='\0';i++){
        message[i] = message[i]^word[i];
    }
    
    printf("your massage encrypted: %s\n",message);
    
    for(int i = 0;message[i]!='\0';i++){
        message[i] = message[i]^word[i];
    }
    printf("your massage: %s",message);
    return 0;
}
