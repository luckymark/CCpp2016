#ifndef SAFEARRAY_H
#define SAFEARRAY_H


class SafeArray
{
    public:
        SafeArray();
        SafeArray(int n);
        virtual ~SafeArray();
        bool result(int n);
        void write(int n,int x);
        int read(int n);

    protected:

    private:
        int* data;
        int maxsize;
};

#endif // SAFEARRAY_H
