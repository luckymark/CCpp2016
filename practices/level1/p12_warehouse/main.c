#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>

struct something{
    char name[20];
    int count;
    int money;
};

struct something nothing;
FILE *show_read;
FILE *delete_write ;
FILE *delete_read ;
FILE *add_write;
FILE *add_read;
FILE *add_writeAtBottom;

int main()
{
    int exit = 0;
    while(exit!=1){
        printf("1.��ʾ����б�\n");
        printf("2.�����\n");
        printf("3.ɾ����¼\n");
        printf("4.�˳�����\n");
        char choice = getch();
        switch(choice){
            case '1':
                show();
                break;
            case '3':
                delete();
                break;
            case '2':
                add();
                break;
            case '4':
                exit = 1;
                break;
        }
    }
    return 0;
}

void add(){
    struct something somethingExist[100];
    for(int i=0;i<100;i++){
        somethingExist[i].money = -1;
    }
    char ifAdd = 'Y';
    while(ifAdd=='Y'||ifAdd=='y'){

        int ifExist;
        ifExist = 0;
        printf("�������ֻ������֣�\n");
        scanf(" %s",&nothing.name);
        printf("�������ֻ�������(����Ϊ�������Ϊ��)��\n");
        scanf(" %d",&nothing.count);
        printf("�������ֻ��ﵥ�ۣ�\n");
        scanf(" %d",&nothing.money);
        add_read = fopen("warehouse.txt","r");
        for(int i=0;fread(&somethingExist[i],sizeof(struct something),1,add_read)!=0;i++){
            if(strcmp(somethingExist[i].name,nothing.name)==0&&somethingExist[i].money == nothing.money){
                somethingExist[i].count = somethingExist[i].count+nothing.count;
                ifExist = 1;
           }
        }
        fclose(add_read);
        add_write = fopen("warehouse.txt","w");
        for(int i=0;i<100;i++){
            if(somethingExist[i].money!=-1){
                fwrite(&somethingExist[i],sizeof(struct something),1,add_write);
            }
        }
        add_writeAtBottom = fopen("warehouse.txt","a+");
        if(!ifExist){
            if(nothing.count>0){
                fwrite(&nothing,sizeof(struct something),1,add_write);
            }else{
                printf("û�����������ʲô�⣡����");
            }
        }
        fclose(add_write);
        printf("�Ƿ������ӣ�(Y/N)\n");
        scanf(" %c",&ifAdd);
        fclose(add_writeAtBottom);

    }
}

void show(){
    int i=1;
    fseek(show_read, 0, SEEK_SET);
    if((show_read = fopen("warehouse.txt","r"))==NULL){
        printf("�򿪲ֿ�ʧ��");
    }
    while(fread(&nothing,sizeof(struct something),1,show_read)!=0){
        printf("(%d).��������:%s,����:%d������:%d\n",i,nothing.name,nothing.count,nothing.money);
        i++;
    }
    fclose(show_read);
}

void delete(){
    show();

    delete_read = fopen("warehouse.txt","r");


    fseek(delete_read, 0, SEEK_SET);
    struct something record[100];
    for (int i=0;i<100;i++){
        record[i].money = -1;
    }
    for(int i=0;fread(&record[i],sizeof(struct something),1,delete_read)!=0;i++){

    }

    int deleteNum = 0;

    printf("��������ɾ���ڼ�����¼\n");
    scanf(" %d",&deleteNum);
    delete_write = fopen("warehouse.txt","w");
    for(int i = 0;i<100;i++){
        if(record[i].money!=-1&&i!=deleteNum-1){
            fwrite(&record[i],sizeof(struct something),1,delete_write);
        }
    }

    fclose(delete_read);fclose(delete_write);

}
