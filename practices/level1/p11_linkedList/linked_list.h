#ifndef P11_LINKEDLIST_LINKED_LIST_H
#define P11_LINKEDLIST_LINKED_LIST_H

struct Node {
    int value;
    struct Node *next;
};

typedef struct LinkedList {
    struct Node *head;
} LinkedList;

LinkedList *ll_new(void);

void ll_free(LinkedList *list);

void ll_append(LinkedList *list, int value);

void ll_reverse(LinkedList *list);

int ll_find(LinkedList *list, int value);

#endif //P11_LINKEDLIST_LINKED_LIST_H
