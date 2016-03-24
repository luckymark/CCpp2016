#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct List{int number;char model[10];struct List *next};
struct Data{int number;char model[10]};
struct Data read;
struct List *head,*last;
void storage();
void display();
void stock_out();
void save();
int num=0;//货物数量
int main()
{
    head=(struct List*)malloc(sizeof(struct List));
    last=(struct List*)malloc(sizeof(struct List));
    head->next=NULL;
    last->next=NULL;
    FILE *fp;
    fp=fopen("data.txt","r");
    while(fscanf(fp,"%s %d",&read.model,&read.number)==2)
    {
        storage(read.model,read.number);
    }
    while(1)
    {
        int judge;
        printf("请输入数字来选择你需要的功能:\n1.显示存货；\n2.入库\n3.出库\n4.退出程序\n");
        scanf("%d",&judge);
        if(judge==1)
        {
            display();
        }
        if(judge==2)
        {
            printf("请输入货物型号与数量，中间用空格隔开");
            char model[10];
            int number;
            scanf("%s %d",model,&number);
            storage(model,number);
        }
        if(judge==3)
        {
            stock_out();
        }
        if(judge==4)
        {
            fclose(fp);
            save();
            exit(1);
        }
    }
    return 0;
}
void display()
{
    struct List *p=head;
    if(num==0)
    {
        printf("当前无存货!\n");
        return;
    }
    printf("当前存货列表为\n");
    for(int i=0;i<num;i++)
    {
         /*if(p->number==0)//库存为0，就当他不存在
         {
             continue;
         }*/
         printf("型号为:%s\t\t数量为:%d\n",p->model,p->number);
         p=p->next;
    }
}
void storage(char model[10],int number)
{
    struct List *p=head;
    for(int i=0;i<num;i++)
    {
        if(num==0)
        {
            break;
        }
        if(strcmp(model,p->model)==0)
        {
            if(p->number!=0)
            {
                printf("检测到仓库中已有此货物，已帮你自动累加\n");
            }
            p->number+=number;
            return;
        }
        if(num==1)
        {
            break;
        }
        p=p->next;
    }
    if(num==0)
    {
        strncpy(head->model,model,10);
        head->number=number;
        head->next=last;
    }
    if(num==1)
    {
        strncpy(last->model,model,10);
        last->number=number;
        head->next=last;
        last->next=NULL;
    }
    if(num>1)
    {
        struct List *p1;
        p1=(struct List*)malloc(sizeof(struct List));
        strncpy(p1->model,model,10);
        p1->number=number;
        last->next=p1;
        p1->next=NULL;
        last=p1;
    }
    num++;
}
void stock_out()
{
    char out[10];
    printf("请输入出库型号：");
    scanf("%s",out);
    struct List *p=head,*p2=head;
    while(p->next!=NULL)
    {
        if(!strcmp(p->model,out))
        {
            int out_number;
            printf("\n要出库的型号为：%s\n库存数量为:%d\n请输入出库的数量：",p->model,p->number);
            scanf("%d",&out_number);
            if(out_number>p->number)
            {
                printf("库存不足，出货失败\n");
                return;
            }
            p->number-=out_number;
            printf("出货成功\n%s型号的剩余库存量为%d",p->model,p->number);
            return;
        }
        p2=p;
        p=p->next;
    }
    printf("找不到\n");
    return;
}
void save()
{
    FILE *fp;
    fp=fopen("data.txt","w+");
    struct List *p=head;
    for(int i=0;i<num;i++)
    {
        if(p->number!=0)
        {
            fprintf(fp,"%s %d\n",p->model,p->number);
        }
        p=p->next;
    }
    fclose(fp);
}
