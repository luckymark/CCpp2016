//
// Created by Administrator on 2016/4/24.
//在部分函数的构造上借鉴了其他程序

#ifndef P03_SAFEARRAY_SAFEARRAY_H
#define P03_SAFEARRAY_SAFEARRAY_H


class SafeArray {
public:
    SafeArray(int max) {
        data = new int[max];
        length = max;
    }

    ~SafeArray() {
        delete[] data;
    }

    int get_length();

    int& set_data(int position);

    int& get_data(int position);

private:
    int *data;
    int length;
};


#endif //P03_SAFEARRAY_SAFEARRAY_H
