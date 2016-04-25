#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>
//----------------
struct node{
    int x;
    node* next = NULL;
};
//-----------------
void printnode(node *head);
node *appendnode(node *p);
node *reverse(node *first);
void findvalue(node *head,int value);

//----------------------
int main() {
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

node *appendnode(node *previous) {
        node *p = (node *)malloc(sizeof(node));//int *p = (int *)malloc(sizeof(int)*10);
        previous -> next = p;
        return p;
}

void printnode(node *head) {
    while(head ->next != NULL){
        printf("%d\n",head -> x);
        head = head -> next;
    }
}

node *reverse(node *first) {
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
void findvalue(node *head,int value) {
    int x = 1;
    while(true){
        if(head -> x == value){
            printf("%d\n",x);
        }
        x++;
        head = head -> next;
        if(head ->next != NULL){
            printf("%d",-1);
            break;
        }
    }
}
