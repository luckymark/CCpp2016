//
// Created by Administrator on 2016/6/15.
//

#ifndef P_ITERATOR_ITERATOR_H
#define P_ITERATOR_ITERATOR_H


class Iterator {
private:
    int a;
    int s[];
public:
    Iterator(queue<int> queue, int m);

    ~Iterator();

    int GetData(int);

    int SetData(int, int);

    int Ahead();

    int Back();

};


#endif //P_ITERATOR_ITERATOR_H
