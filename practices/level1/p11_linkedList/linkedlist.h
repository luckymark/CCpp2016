#ifndef linkedlist_h__
#define linkedlist_h__

typedef struct linkedlist {
    struct linkedlist *next;
    int value;
} linkedlist;

linkedlist *find(linkedlist *plist, int value);

linkedlist *next(linkedlist *plist);

int empty_list(linkedlist *plist);

linkedlist *reverse(linkedlist *plist);

void free_list(linkedlist *plist);

int find_index(linkedlist *plist, int value);

void print_list(linkedlist *plist);

linkedlist *construct_with_array(int a[], int length);

#endif
