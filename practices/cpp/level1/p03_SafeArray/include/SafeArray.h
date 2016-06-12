#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include<iostream>
using namespace std;
class SafeArray
{
    public:
        SafeArray();
        SafeArray(int length);
        int getItem(int num);
        void setItem(int num,int value);
        virtual ~SafeArray();
    protected:
    private:
        int *data;
        int length=100;
};

#endif // SAFEARRAY_H
