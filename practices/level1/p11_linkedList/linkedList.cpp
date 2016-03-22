#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int x;
    int* next = NULL;
};
int main(){
    struct node first;
    for(int i = 0;i<100;i++){
        struct node *p = (struct node *)malloc(sizeof(struct node));//int *p = (int *)malloc(sizeof(int)*10);
        first.next = &(p -> x);
        p -> x = i;
    }
}
