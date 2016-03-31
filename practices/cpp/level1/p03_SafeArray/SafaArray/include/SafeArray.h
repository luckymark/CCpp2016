#ifndef SAFEARRAY_H
#define SAFEARRAY_H


class SafeArray
{
    public:
        SafeArray(int capbility)
        {
            this->capbility=capbility;
            data=new int[capbility];
        }
        ~SafeArray()
        {
            delete data;
        }
        void insert(int pos,int value);
        int get(int pos);
    private:
        int *data;
        int capbility;
};

#endif // SAFEARRAY_H
