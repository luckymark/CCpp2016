#include <stdlib.h>
#include <stdio.h>

#include "linked_list.h"

static linked_list *auxiliary_reverse(linked_list *plist, linked_list *first) {
    if (plist->next == NULL) {
        return plist;
    } else {
        linked_list *pnext = plist->next;
        linked_list *last = auxiliary_reverse(pnext, first);
        pnext->next = plist;
        if (first == plist) {
            plist->next = NULL;
        }
        return last;
    }
}

linked_list *find(linked_list *plist, int value) {
    if (plist == NULL) {
        return NULL;
    } else if (plist->value == value) {
        return plist;
    } else {
        return find(plist->next , value);
    }
}

int find_index(linked_list *plist, int value) {
    if (plist->value == value) {
        return 0;
    } else if (empty_list(plist)) {
        return -1;
    } else {
        int subindex = find_index(plist->next, value);
        return subindex == -1 ? -1 : 1 + subindex;
    }
}

linked_list *reverse(linked_list *plist) {
    return auxiliary_reverse(plist, plist);
}

linked_list *next(linked_list *plist) {
    return plist->next;
}

int empty_list(linked_list *plist) {
    return (plist == NULL) ? 1 : 0;
}

linked_list *construct_with_array(int a[], int length) {
    if (length == 0) {
        return NULL;
    } else {
        linked_list *plist = (linked_list*) malloc(sizeof(linked_list));
        plist->next = construct_with_array(&a[1], length - 1);
        plist->value = a[0];
        return plist;
    }
}

void print_list(linked_list *plist) {
    if (plist != NULL) {
        printf("%d%s", plist->value, empty_list(next(plist)) ? "\n" : "->");
        print_list(next(plist));
    }
}

void free_list(linked_list *plist) {
    if (plist != NULL) {
        free_list(plist->next);
        free(plist);
    }
}
