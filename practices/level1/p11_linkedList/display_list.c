#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char const *argv[]) {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    linkedlist *plist = construct_with_array(a, 7);
    print_list(plist);
    plist = reverse(plist);
    print_list(plist);
    printf("index of 2 is %d\n", find_index(plist, 2));
    free_list(plist);
    return 0;
}
