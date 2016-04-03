#ifndef HOMEWORK_LIST_H
#define HOMEWORK_LIST_H
#include <cstdio>
#include <iostream>
class List {
public:
    List(int value = 0, int num = 0) {
        this->value = value;
        this->num = num;
        this->next = NULL;
    }
    void add(int value = 0);

    void remove();

    void view();

    int find(int number);

    int nextFind(int prePosition = 0, int number = 0);

    void kill();//防止泄露

    List *reverse();

private:
    int value, num;
    List *next;
};
#endif
