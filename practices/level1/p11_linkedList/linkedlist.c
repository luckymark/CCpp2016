#include <stdlib.h>
#include <stdio.h>

#include "linkedlist.h"

static linkedlist *auxiliary_reverse(linkedlist *plist, linkedlist *first) {
    if (plist->next == NULL) {
        return plist;
    } else {
        linkedlist *pnext = plist->next;
        linkedlist *last = auxiliary_reverse(pnext, first);
        pnext->next = plist;
        if (first == plist) {
            plist->next = NULL;
        }
        return last;
    }
}

linkedlist *find(linkedlist *plist, int value) {
    if (plist == NULL) {
        return NULL;
    } else if (plist->value == value) {
        return plist;
    } else {
        return find(plist->next , value);
    }
}

linkedlist *reverse(linkedlist *plist) {
    return auxiliary_reverse(plist, plist);
}

linkedlist *next(linkedlist *plist) {
    return plist->next;
}

int empty_list(linkedlist *plist) {
    return plist ? 1 : 0;
}

linkedlist *construct_with_array(int a[], int length) {
    if (length == 0) {
        return NULL;
    } else {
        linkedlist *plist = (linkedlist*) malloc(sizeof(linkedlist));
        plist->next = construct_with_array(&a[1], length - 1);
        plist->value = a[0];
        return plist;
    }
}

void print_list(linkedlist *plist) {
    if (plist != NULL) {
        printf("%d%s", plist->value, empty_list(next(plist)) ? "->" : "\n");
        print_list(next(plist));
    }
}

void free_list(linkedlist *plist) {
    if (plist != NULL) {
        free_list(plist->next);
        free(plist);
    }
}
