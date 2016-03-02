#ifndef linked_list_h__
#define linked_list_h__

typedef struct linked_list {
    struct linked_list *next;
    int value;
} linked_list;

linked_list *find(linked_list *plist, int value);

linked_list *next(linked_list *plist);

int empty_list(linked_list *plist);

linked_list *reverse(linked_list *plist);

void free_list(linked_list *plist);

int find_index(linked_list *plist, int value);

void print_list(linked_list *plist);

linked_list *construct_with_array(int a[], int length);

#endif
