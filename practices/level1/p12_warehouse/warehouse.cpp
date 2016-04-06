#include<stdio.h>
#include<string.h>
void showList(FILE *fp);
void add(FILE *fp);
void del(FILE *fp);
//---------------------
int main(){
    int chioce;
    FILE *fp;
    fp = fopen("D:\\Repository\\CCpp2016\\practices\\level1\\p12_warehouse\\data.txt", "r+");
    while(true){
        printf("1.showList\n2.add\n3.out\n4.exit\n");
        scanf("%d",&chioce);
        switch (chioce) {
            case 1: showList(fp); break;
            case 2: add(fp); break;
            case 3: del(fp); break;
            case 4: fclose(fp); return 0; break;
            default: printf("error");
        }
        printf("success\n");
    }
}

void showList(FILE *fp){
    char ch;
    ch=fgetc(fp);
    while(ch!= EOF){
        putchar(ch);
        ch=fgetc(fp);
    }
}

void add(FILE *fp){
    char newtype[50];
    char newnum[50];
    printf("type: ");
    scanf("%s",newtype);
    printf("number: ");
    scanf("%s",newnum);
    strcat(newtype,": ");
    strcat(newtype,newnum);
    strcat(newtype,"\n");
    fseek(fp,0,SEEK_END);
    fputs(newtype,fp);
}
