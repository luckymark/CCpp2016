#include <stdio.h>
#include "linked_list.h"

int main(int argc, char const *argv[]) {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    linked_list *plist = construct_with_array(a, 7);
    print_list(plist);
    plist = reverse(plist);
    print_list(plist);
    printf("index of 5 is %d\n", find_index(plist, 5));
    free_list(plist);
    return 0;
}
