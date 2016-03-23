#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int x;
    node* next = NULL;
};
void printnode(node temp);
//程序主体
int main(){
    node first;
    node temp = first;
    for(int i = 0;i<100;i++){
        node *p = (node *)malloc(sizeof(node));//int *p = (int *)malloc(sizeof(int)*10);
        p -> x = i;
        temp.next = p;
        temp = *p;
    }
    printnode(first);
    return 0;
}

void printnode(node temp){
    do{
        temp = *temp.next;
        printf("%d\n",temp.x);
    }while(temp.next!=NULL);
}
