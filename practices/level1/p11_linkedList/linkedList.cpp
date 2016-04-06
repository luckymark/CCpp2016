#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
//结构体
struct node{
    int x;
    node* next = NULL;
};
//函数原型
void printnode(node *head);
node *appendnode(node *p);
node *reverse(node *first);

//程序主体
int main(){
    node *first = (node *)malloc(sizeof(node));
    node *last = first;
    for(int i = 0;i<100;i++){
        last -> x = i;
        last = appendnode(last);
    }
    printnode(first);
    first = reverse(first);
    printnode(first);
    return 0;
}

node *appendnode(node *previous){
        node *p = (node *)malloc(sizeof(node));//int *p = (int *)malloc(sizeof(int)*10);
        previous -> next = p;
        return p;
}

void printnode(node *head){
    while(head ->next != NULL){
        printf("%d\n",head -> x);
        head = head -> next;
    }
}

node *reverse(node *first){
    node *previous = first;
    node *after = first -> next;
    previous -> next = NULL;
    while(true){
        if(after == NULL){
            first -> next = previous;
            return first;
        }else{
            first = after;
            after = after -> next;
            first -> next = previous;
            previous = first;
        }
    }
}
