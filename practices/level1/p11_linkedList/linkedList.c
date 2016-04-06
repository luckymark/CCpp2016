#include <stdio.h>
#include <stdlib.h>

typedef struct points{
    int a;
    int number;
    struct points *next;
} point;

typedef struct list{
    point *head;
    point *last;
} linkList;

void addList(linkList *p);
linkList* setLinkList(void);
int searchFirst(int n,linkList* p);
int searchSecond(int n,linkList* p);
void resetLinkList(linkList *s);

int main()
{
    linkList* s=NULL;
    s=setLinkList();
    int x;
    printf("请输入数据，输入end结束\n");
    while(scanf("%d",&x)==1){
        addList(s);
        s->last->a=x;
    }
    resetLinkList(s);
    printf("%d\n",searchFirst(5,s));
    printf("%d",searchSecond(5,s));
    return 0;
}

void resetLinkList(linkList *s){
    point *p,*temp1=NULL,*temp2=NULL;
    p=s->head;
    for(int i=1;i<=(s->last->number);i++){
        temp1=p->next;
        p->next=temp2;
        p->number=(s->last->number)+1-i;
        temp2=p;
        p=temp1;
    }
    temp1=s->head;
    s->head=s->last;
    s->last=temp1;
}

void addList(linkList *p){
    int i;
    if(p->head==NULL){
        p->head=(point*)malloc(sizeof(point));
        p->last=p->head;
        p->last->next=NULL;
        p->head->number=1;
    }else{
        p->last->next=(point*)malloc(sizeof(point));
        i=(p->last->number)+1;
        p->last=p->last->next;
        p->last->number=i;
        p->last->next=NULL;
    }
}

linkList* setLinkList(void){
    linkList* info=(linkList*)malloc(sizeof(linkList));
    info->head=NULL;
    info->last=NULL;
    return info;
}

int searchFirst(int n,linkList* p){
    point* x=p->head;
    int i=-1;
    do{
        if(n==x->a){
            i=x->number;
            break;
        }
        x=x->next;
    }while((x->next!=NULL));
    return i;
}

int searchSecond(int n,linkList* p){
    point* x=p->head;
    int i=-1,j=2;
    do{
        if(n==x->a){
            j--;
        }
        if(j==0){
            i=x->number;
            break;
        }
        x=x->next;
    } while((x->next!=NULL));
    return i;
}
