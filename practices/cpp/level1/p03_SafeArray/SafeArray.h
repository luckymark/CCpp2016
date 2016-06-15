#ifndef SAFEARRAY_H
#define SAFEARRAY_H


class SafeArray
{
    public:
        SafeArray();
        SafeArray(int n);
        virtual ~SafeArray();
        void write(int n,int x);
        int read(int n);

    protected:

    private:
        int* data;
        int maxsize;
        bool result(int n);
};


#endif
