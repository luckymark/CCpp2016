#include "List.h"
#include <stack>
void List::add(int value) {
    List *now = this;
    while (now->next != NULL) {
        now = now->next;
    }
    List *myNext = new List(value, now->num + 1);
    now->next = myNext;
}
void List::remove() {
    if (this->next == NULL) {
        printf("Error!\n");
        return;
    }
    List *now = this;
    while (now->next != NULL) {
        now = now->next;
    }
    delete now;
    List *newFinal = this;
    while (newFinal->next != now) {
        newFinal = newFinal->next;
    }
    newFinal->next = NULL;
}
void List::view() {
    List *now = this->next;
    while (now != NULL) {
        printf("%d ", now->value);
        now = now->next;
    }
    puts("");
}
int List::find(int number) {
    List *now = this->next;
    while (now != NULL) {
        if (now->value == number) {
            return now->num;
        }
        now = now->next;
    }
    return -1;
}
int List::nextFind(int prePosition, int number) {
    List *now = this->next;
    while (now != NULL && now->num <= prePosition) {
        now = now->next;
    }
    while (now != NULL) {
        if (now->value == number) {
            return now->num;
        }
        now = now->next;
    }
    return -1;
}
void List::kill() {
    List *now = this;
    while (now != NULL) {
        delete now;
        now = now->next;
    }
}
List *List::reverse() {
    List *now = this->next;
    std::stack<int> stack;
    while (now != NULL) {
        stack.push(now->value);
        now = now->next;
    }
    List *newList = new List;
    this->kill();
    while (!stack.empty()) {
        newList->add(stack.top());
        stack.pop();
    }
    return newList;
}
