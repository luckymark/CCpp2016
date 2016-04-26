//
//  main.c
//  wareHouse
//
//  Created by 陈浩贤 on 16/3/24.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int finished;
//char path[150]="/Users/caoxiann/Desktop/c/c &c++lesson/CCpp2016/practices/level1/p12_warehouse/wareHouse/list.txt";
char path[20]="list.txt";
struct Cargo{
    char name[20];
    char id[20];
    int quantity;
    char str[100];
    struct Cargo *next;
};

struct Cargo *head,*theTail;
int searched;
void printMenu();
void judgeWhitchToDo(int number);
void displayCargoList();
void depositCargo();
void takeOutCargo();
void backToMenu();
int searchCargo(char name[],char number[]);

struct Cargo* readAllFormFile();

int main(int argc, const char * argv[]) {
    // insert code here...
    
    searched=0;
    head=(struct Cargo*)malloc(sizeof(struct Cargo));
    finished=0;
    printMenu();
    return 0;
}

void printMenu(){
    int whichToDo;
    
    while (finished==0) {
        printf("1.显示存货列表\n");
        printf("2.入库\n");
        printf("3.出库\n");
        printf("0.退出程序\n");
        printf("\n");
        printf("请输入对应数字进入该功能\n");
        
        scanf("%d",&whichToDo);
        
        
        judgeWhitchToDo(whichToDo);
    }
}

void judgeWhitchToDo(int number){
    system("clear");
    if (number==1) {
        displayCargoList();
    }else if (number==2){
        depositCargo();
    }else if (number==3){
        takeOutCargo();
    }else if (number==0){
        finished=1;
    }else{
        printf("请输入正确指令\n");
        backToMenu();
    }
    
}

void displayCargoList(){
    FILE *fp=fopen(path, "r");
    if (fp==NULL) {
        printf("can't open\n");
    }else{
//        char name[20],number[20];
//        int quantity;
        printf("商品名称   \t\t编号  \t\t   数量\n");
        printf("**************************************\n");
        
//        while (fscanf(fp, "%s %s %d",name,number,&quantity)!=EOF) {
//            printf("%-10s\t\t%-10s\t\t%d",name,number,quantity);
//            printf("\n");
//        }
        readAllFormFile();
        struct Cargo *p=head;
        while (p->next!=NULL) {
            printf("%-10s\t\t %-10s\t\t %d",p->name,p->id,p->quantity);
            printf("\n");
            p=p->next;
        }
        printf("\n");
    }
    fclose(fp);
    backToMenu();
    
}

void depositCargo(){
    
    struct Cargo cg;
    readAllFormFile();
    printf("请输入存入的商品名字\n");
    scanf("%s",cg.name);
    printf("请输入存入商品的编号\n");
    scanf("%s",cg.id);
    printf("请输入存入商品的数量\n");
    scanf("%d",&cg.quantity);
    int n=searchCargo(cg.name, cg.id);
    if (n!=-1) {
        struct Cargo *p;
        p=head;
        int i=1;
        FILE *fw=fopen(path,"w,ccs=UTF-8");
        while (p->next!=NULL) {
            if (i==n) {
                p->quantity=p->quantity+cg.quantity;
                printf("%s 的数量增加了 %d",p->name,p->quantity);
            }
            fprintf(fw,"%s %s %d\n",p->name,p->id,p->quantity);
            p=p->next;
            i++;
        }
        fclose(fw);
    }else{
    FILE *fp=fopen(path, "a+");
    fprintf(fp,"%s %s %d\n",cg.name,cg.id,cg.quantity);
    fclose(fp);
    }
    
    printf("入库成功！\n");
    
    backToMenu();
}
void takeOutCargo(){
    struct Cargo cg;
    printf("请输入出库的商品名:\n");
    scanf("%s",cg.name);
    printf("请输入出库的商品编号\n");
    scanf("%s",cg.id);
    printf("请输入出库的商品数量\n");
    scanf("%d",&cg.quantity);
    
    int n=searchCargo(cg.name, cg.id),i=1;
    if (n!=-1) {
        readAllFormFile();
        struct Cargo *p=head;
        FILE *fw=fopen(path, "w");
        while (p->next!=NULL) {
            if (n==i) {
                if (p->quantity-cg.quantity>0) {
                    p->quantity=p->quantity-cg.quantity;
                }else if (p->quantity-cg.quantity==0){
                    p=p->next;
                }else{
                    printf("要出库的数量大于存货量\n");
                }
            }
            fprintf(fw, "%s %s %d\n",p->name,p->id,p->quantity);
            p=p->next;
            i++;
        }
        fclose(fw);
    }else{
        printf("要出库的商品不存在\n");
        
    }
    backToMenu();
}

void backToMenu(){
    printf("\n按0回到目录\n");
    int option;
    scanf("%d",&option);
    printf("option:%d\n",option);
    if (option==0) {
        system("clear");
    }else{
        system("clear");
        printf("请输入正确指令\n");
        backToMenu();
    }
}

int searchCargo(char name[],char number[]){
    char checkName[20],checkNumber[20];
    int checkQquantity;
    int n=0;
    FILE *fp=fopen(path, "r");
    while (fscanf(fp, "%s %s %d",checkName,checkNumber,&checkQquantity)!=EOF) {
        n++;
        if (strcmp(checkName, name)==0&&strcmp(checkNumber, number)==0) {
            
            printf("n:%d\n",n);
            fclose(fp);
            return n;
        }
    }
    fclose(fp);
    
    return -1;
}

struct Cargo* readAllFormFile(){
    if (searched==0) {
        FILE *fr=fopen(path, "r");
        struct Cargo *p,*tail;
        
        p=head;
        while (fscanf(fr, "%s %s %d",p->name,p->id,&p->quantity)!=EOF) {
            tail=(struct Cargo*)malloc(sizeof(struct Cargo));
            p->next=tail;
            
            p=tail;
            searched++;
        }
        fclose(fr);
        theTail=p;
        p->next=NULL;
        
    }else{
        struct Cargo cg;
        FILE *fr=fopen(path, "r");
        int count=1;
        while (fscanf(fr, "%s %s %d",cg.name,cg.id,&cg.quantity)!=EOF ){
            if (searched<count) {
                struct Cargo *p=(struct Cargo*)malloc(sizeof(struct Cargo));
                theTail->next=p;

                p->quantity=cg.quantity;
                strcpy(p->name, cg.name);
                strcpy(p->id, cg.id);
                
                theTail=p;
                searched++;
            }
            count++;
        }
        fclose(fr);
        
    }
   
    
    return head;
}