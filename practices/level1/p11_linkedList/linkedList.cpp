#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node{
    int x;
    node* next = NULL;
};
int main(){
    node first;
    node temp = first;
    for(int i = 0;i<100;i++){
        node *p = (node *)malloc(sizeof(node));//int *p = (int *)malloc(sizeof(int)*10);
        temp.next = p;
        p -> x = i;
        temp = *p;
    }
}
