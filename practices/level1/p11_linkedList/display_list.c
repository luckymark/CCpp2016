#include <stdio.h>
#include "linkedlist.h"

int main(int argc, char const *argv[]) {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    linkedlist *plist = construct_with_array(a, 5);
    print_list(plist);
    plist = reverse(plist);
    print_list(plist);
    print_list(find(plist, 3));
    return 0;
}
