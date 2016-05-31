#include <stdio.h>
#include <stdlib.h>
#define length 11


//void initializeList(struct list **list1,int len);
//int search(struct list *list1);
struct list{
    int value;
    struct list *next ;
};
int order = 1;
struct list *find;
struct list *list1[length];

int main()
{

    initializeList(list1,length);
    int time = search(list1[0],5);
    printf("%d\n",time);
    time = search(list1[order],5);
    time = time +1;//跳过了一个节点，因此次数+1
    printf("%d\n",time);
    reverse(list1[0]);
    return 0;
}

//初始化链表（第n个节点值为n-1，第最后一个个也为5）
void initializeList(struct list **list1,int len){
    list1[0] = (struct list *)malloc(sizeof(struct list));
    list1[0]->value = 0;
    for(int i=0;i<len-1;i++){
        list1[i+1] = (struct list *)malloc(sizeof(struct list));
        list1[i+1]->value = i+1;
        list1[i]->next = list1[i+1];
    }
    list1[len-1]->value = 5;
    list1[len-1]->next = NULL;
}

int search(struct list *head,int value){
    find = head;
    while(1){

        if(find->value==value){
            return order;
        }
        if(find->next!=NULL){
            order = order +1;
            find = find->next;

        }else{
            break;
        }

    }
    return -1;
}

void reverse(struct list *head){
    struct list *Last,*Next = NULL,*temp = NULL;
    Last=head;
    Next=Last->next;
    while (Next->next!=NULL) {

        temp=Next->next;
        Next->next = Last;
        Last=Next;
        Next = temp;
    }

}
