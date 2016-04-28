#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAMELEN 25
struct list
{   int number;
	char name[NAMELEN+1];
	struct list *next;
};
struct data
{
	int number;
	char name[NAMELEN+1];
};
struct data read;
struct list *first,*last;
void choose();
void Insert(char name[NAMELEN+1],int number);
void ShowList();
void OutList();
void Save();
int num=0;
int main()
{
    first=(struct list*)malloc(sizeof(struct list));
    last=(struct list*)malloc(sizeof(struct list));
    first->next=NULL;
    last->next=NULL;
    FILE *fp;
    fp=fopen("D:\\list.txt","rb");
    while(fscanf(fp,"%s %d",&read.name,&read.number)==2)
    {
        Insert(read.name,read.number);
    }
    for(;;)
    {
    	choose();
    }
    return 0;
}
void choose()
{
	FILE *fp;
    fp=fopen("D:\\list.txt","r");
	int n;
	printf("1.显示货存；2.入库3.出库4.退出程序\n");
    scanf("%d",&n);
    switch(n)
    {
    	case 1:
    		ShowList();
    	break;
    	case 2:
    		printf("请输入货物型号与数量");
        	char name[NAMELEN+1];
        	int change;
        	scanf("%s %d",name,&change);
        	Insert(name,change);
        	break;
        case 3:
        	printf("请输入出库型号：");
        	OutList();
        	break;
        case 4:
        	fclose(fp);
            Save();
            exit(1);
    }
}
void ShowList()
{
	struct list*p=first;
	for(p=first;p!=NULL;p=p->next)
	{
		printf("%s:",p->name);
		printf("%d\n",p->number);
	}
}
void Insert(char name[NAMELEN+1],int change)
{
    struct list *p=first;
    for(int i=0;i<num;i++)
    {
        if(0==num&&1==num)
        {
            break;
        }
        if(strcmp(name,p->name)==0)
        {
            p->number+=change;
            return;
        }
        p=p->next;
    }
    if(0==num)
    {
        strncpy(first->name,name,NAMELEN+1);
        first->number=change;
        first->next=last;
    }
    if(1==num)
    {
        strncpy(last->name,name,NAMELEN+1);
        last->number=change;
        first->next=last;
        last->next=NULL;
    }
    if(num>1)
    {
        struct list *p1;
        p1=(struct list*)malloc(sizeof(struct list));
        strncpy(p1->name,name,10);
        p1->number=change;
        last->next=p1;
        p1->next=NULL;
        last=p1;
    }
    num++;
}
void OutList()
{
    char out[NAMELEN+1];
    
    scanf("%s",out);
    struct list *p=first;
    for(int i=0;i<num;i++)
    {
        if(!strcmp(p->name,out))
        {
            int Out;
            printf("\n%s\n:%d\n：",p->name,p->number);
            scanf("%d",&Out);
            if(Out>p->number)
            {
                printf("货存不足\n");
                return;
            }
            p->number-=Out;
            printf("出货成功\n%s型号的剩余货存量为%d",p->name,p->number);
            return;
        }
        p=p->next;
    }
    printf("不存在\n");
    return;
}
void Save()
{
    FILE *fp;
    fp=fopen("D:\\list.txt","wb");
    struct list *p=first;
    for(int i=0;i<num;i++)
    {
        if(p->number!=0)
        {
            fprintf(fp,"%s %d\n",p->name,p->number);
        }
        p=p->next;
    }
    fclose(fp);
    p=first;
    for(int i=0;i<num;i++)
    {
        struct list *p1=p->next;
        p=p1;
    }
}