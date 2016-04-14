//
//  main.c
//  linkedList
//
//  Created by 陈浩贤 on 16/3/21.
//  Copyright © 2016年 陈浩贤. All rights reserved.
//

#include <stdio.h>
struct slist{
    int value;
    
    struct slist *next;
};
struct slist *head,*current;
void initSlistForLength(int length);
void reverseSlist();
int findTheValue(int valueToSearch);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
 
    initSlistForLength(10);
    reverseSlist();
    current=head;
    int indexOfFive;
    while ((indexOfFive=findTheValue(5))!=-1) {
        printf("index:%d\n",indexOfFive);
    }
    printf("index:%d\n",indexOfFive);
    
    
    return 0;
}

void initSlistForLength(int length){
    struct slist *p,*q;
    p=(struct slist *)malloc(sizeof(struct slist));
    for (int i=0; i<=length; i++){
        
        if (i==0) {
            head=p;
            
        }
        
        p->value=5*i;
        printf("value:%d\n",p->value);
        q=(struct slist *)malloc(sizeof(struct slist));
        
        p->next=q;
        p=q;
        
        if (i==length+1) {
            p->next='\0';
        }
    }
}


void reverseSlist(){
    struct slist *p,*q = NULL,*temp = NULL;
    p=head;
    
    while (p) {
        q=p->next;
        p->next=temp;
        temp=p;
        p=q;
    }
    head=temp;
}

int findTheValue(int valueToSearch){
    struct slist *p,*q=NULL;
    p=current->next;
    int i=1;
    for (; p; i++) {
        if (p->value==valueToSearch) {
            current=p;
            return i;
        }
        q=p->next;
        p=q;
    }
    
    return -1;
}
