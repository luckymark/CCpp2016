//功能要求：
//在main函数中创建一个单向链表；
//遍历该链表，依次现实各节点的value；
//将该链表所有节点反序；
//在该链表中查找第一个值为5的节点，如果找到则返回该节点的序号，否则返回－1；
//查找下一个值为5的节点，返回值同上；
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* add_to_list(struct node* list, int n){
    struct node* new_node;
    new_node = malloc(sizeof(struct node));
    if(new_node == NULL) {
        printf("Error: malloc failed in add_to list.\n");
        exit(EXIT_FAILURE);
    }
    new_node -> value =n;
    new_node -> next = list;
    return new_node;
}

int search_node(struct node* list,int n){
    struct node *p;

    for(p=list; p != NULL; list=list -> next){
        if(list -> value ==5){
            return list -> value;
        }
    }
    return -1;
}

int main(void) {
    struct node *list1,*list2,*list3,*list4,*list5,*list6;

    //initiation
    list6 ->next =NULL;
    list6 ->value = 6;
    list5=add_to_list(list6,6);
    list4=add_to_list(list5,5);
    list3=add_to_list(list4,4);
    list2=add_to_list(list3,3);
    list1=add_to_list(list2,2);

    //reverse
    list6 ->next = list5;
    list5 ->next = list4;
    list4 ->next = list3;
    list3 ->next = list2;
    list2 ->next = list1;
    list1 ->next = NULL;

    return 0;
}