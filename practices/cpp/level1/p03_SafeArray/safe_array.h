#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H


class safe_array
{
    public:
        safe_array(int capbility);
        ~safe_array();
        bool is_safe(int a);
        void pop(int b,int c);
        int load(int a);
    protected:
    private:
        int *data;
        int len;
};

#endif // SAFE_ARRAY_H
