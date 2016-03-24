#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void select(int n);
void showList(void);
void addInList(void);
void outList(void);
void stop(void);
long int findType(FILE* fp,char* s);

int main()
{
    int x;
    while(1){
        printf("选择模块：\n1.显示库存列表\t2.入库\t3.出库\t4.退出\n");
        scanf("%d",&x);
        select(x);
    }
    return 0;
}


void select(int n){
    switch (n){
    case 1:
        showList();
        break;
    case 2:
        addInList();
        break;
    case 3:
        outList();
        break;
    case 4:
        stop();
        break;
    default:
        printf("无效输入！\n");
    }
}

void showList(){
    FILE* fp=NULL;
    if ((fp=fopen("List","rb"))==NULL){
        printf("打开失败！请检查文件是否存在！");
        exit(0);
    }
    char *s;
    s=(char*)malloc(100*sizeof(char));
    while(!feof(fp)){
        fscanf(fp,"%s\n",s);
        printf("%s\n",s);
    }
    fclose(fp);
}

void addInList(){
    char type[100];
    int n,x;
    long int where;
    FILE* fp;
    printf("请输入货物种类：");
    scanf("%s",type);
    printf("请输入入库数量：");
    scanf("%d",&n);
    if((fp=fopen("List","rb+"))!=NULL){
        where=findType(fp,type);
        fclose(fp);
        if(where!=-1){
            fp=fopen("List","rb+");
            fseek(fp,where,0);
            fscanf(fp,"%d",&x);
            fseek(fp,where,0);
            fprintf(fp,"%d",n+x);
            fclose(fp);
        }else{
            fp=fopen("List","ab");
            fprintf(fp,"%s:%d\r\n",type,n);
            fclose(fp);
        }
    }else{
        fp=fopen("List","wb");
        fprintf(fp,"%s:%d\r\n",type,n);
        fclose(fp);
    }
}


void outList(){
    char type[100];
    char temp[100];
    int n,x;
    long int where;
    FILE* fp;
    printf("请输入货物种类：");
    scanf("%s",type);
    printf("请输入出库数量：");
    scanf("%d",&n);
    if((fp=fopen("List","rb+"))!=NULL){
        where=findType(fp,type);
        fclose(fp);
        if(where!=-1){
            fp=fopen("List","rb+");
            fseek(fp,where,0);
            fscanf(fp,"%d",&x);
            fseek(fp,where,0);
            if(x-n>=0){
                itoa(x,temp,10);
                for(int i=0;i<strlen(temp);i++){
                    fprintf(fp," ");
                }
                fseek(fp,where,0);
                fprintf(fp,"%d",x-n);
                fclose(fp);
            }else{
                printf("存货不足，剩余%d件\n",x);
            }
        }else{
            printf("无该种货物\n");
        }
    }else{
        printf("打开失败！请检查文件是否存在！\n");
    }
 }

void stop(){
    exit(0);
}

long int findType(FILE* fp,char* s){
    int x=0,i=0;
    char type[100];
    while(!feof(fp)){
        fgets(type,100,fp);
        if((strstr(type,s))==NULL){
            x=x+strlen(type);
        }else{
            i=1;
            break;
        }
    }
    if(i==1){
        x=x+sizeof(*s)+1;
    }else{
        x=-1;
    }
    return x;
}
