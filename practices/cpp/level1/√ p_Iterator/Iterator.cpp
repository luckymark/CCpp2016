//
// Created by Administrator on 2016/6/15.
//

#include "Iterator.h"

Iterator::Iterator(queue<int> queue, int m) {
    int s = new int[m];
    a = 0;
}

Iterator::~Iterator() {
    delete s;
}

int Iterator::GetData(int n) {
    return s[n - 1];
}

int Iterator::SetData(int n, int m) {
    s[n - 1] = m;
    return m;
}

int Iterator::Ahead() {
    int b = a;
    a = (a + 1) % m;
    return s[b];
}

int Iterator::Back() {
    int b = a;
    a = (a + m - 1) % m;
    return s[b];
}