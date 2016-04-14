#include <stddef.h>
#include <stdlib.h>
#include "linked_list.h"

struct Node *ll_newNode(int value) {
    struct Node *n = (struct Node *) malloc(sizeof(struct Node));
    n->value = value;
    n->next = NULL;
    return n;
}

void ll_append(LinkedList *list, int value) {
    if (list->head == NULL) {
        list->head = ll_newNode(value);
    } else {
        struct Node *n = list->head;
        while (n->next != NULL) {
            n = n->next;
        }
        n->next = ll_newNode(value);
    }
}

void ll_reverse(LinkedList *list) {
    int len = 0;
    struct Node *n = list->head;
    while (n != NULL) {
        ++len;
        n = n->next;
    }
    struct Node *newHead = NULL;
    for (int i = 0; i < len; ++i) {
        struct Node *p = NULL;
        n = list->head;
        while (n->next != NULL) {
            p = n;
            n = n->next;
        }
        if (i == 0) {
            newHead = n;
        }
        n->next = p;
        if (p != NULL) {
            p->next = NULL;
        }
    }
    list->head = newHead;
}

int ll_find(LinkedList *list, int value) {
    struct Node *n = list->head;
    int i = 0;
    while (n != NULL) {
        if (n->value == value) {
            return i;
        }
        ++i;
        n = n->next;
    }
    return -1;
}

LinkedList *ll_new(void) {
    LinkedList *l = (LinkedList *) malloc(sizeof(LinkedList));
    l->head = NULL;
    return l;
}

void ll_free(LinkedList *list) {
    struct Node *p = list->head;
    while (p != NULL) {
        struct Node *n = p->next;
        free(p);
        p = n;
    }
    free(list);
}













