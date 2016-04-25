#include<stdio.h>
#include<string.h>
void showList(FILE *fp);
void addToWare(FILE *fp);
void outWare(FILE *fp);
void getIn(FILE *fp);
char data[1000];
//---------------------
int main() {
    int chioce;
    FILE *fp;
    fp = fopen("D:\\Repository\\CCpp2016\\practices\\level1\\p12_warehouse\\data.txt", "r+");
    while(true){
        printf("1.showList\n2.add\n3.out\n4.exit\n");
        scanf("%d",&chioce);
        switch (chioce) {
            case 1: showList(fp); break;
            case 2: addToWare(fp); break;
            case 3: outWare(fp); break;
            case 4: fclose(fp); return 0; break;
            default: printf("error");
        }
        printf("success\n");
    }
}

void showList(FILE *fp) {
    char ch;
    fseek(fp,0,SEEK_SET);
    ch=fgetc(fp);
    while(ch!= EOF){
        putchar(ch);
        ch=fgetc(fp);
    }
}

void addToWare(FILE *fp) {
    char newtype[50];
    char newnum[50];
    getIn(fp);
    printf("type: ");
    scanf("%s",newtype);
    printf("number: ");
    scanf("%s",newnum);
    strcat(newtype,": ");
    strcat(newtype,newnum);
    strcat(newtype,"\n\0");
    fseek(fp,0,SEEK_END);
    fputs(newtype,fp);
}
void outWare(FILE *fp) {
    getIn(fp);

}
void getIn(FILE *fp) {
    char ch;
    memset(data,'\0',sizeof(data)/data[0]);
    fseek(fp,0,SEEK_SET);
    while(true){
        ch=fgetc(fp);
        strcat(data,ch+"");
        if(ch!=EOF){
            strcat(data,"\0");
            break;
        }
    }
}
