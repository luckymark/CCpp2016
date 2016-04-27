#include "linked_list.h"

#include <iostream>
#include <cassert>

using namespace std;

int main() {
    LinkedList *list = ll_new();
    assert(list != NULL);
    for (int i = 0; i <= 6; ++i) {
        ll_append(list, i);
    }
    assert(ll_find(list, 5) == 5);
    assert(ll_find(list, 7) == -1);
    ll_reverse(list);
    assert(ll_find(list, 5) == 1);
    assert(ll_find(list, 7) == -1);
    ll_free(list);
}