#ifndef SAFEARRAY_H
#define SAFEARRAY_H


class SafeArray
{
    public:
        SafeArray(int capbility);
        ~SafeArray();
        bool is_safe(int a);
        void pop(int b,int c);
        int load(int a);
    protected:
    private:
        int *data;
        int capbility;
};

#endif // SAFEARRAY_H
