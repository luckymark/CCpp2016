#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#define MAX 100
class SafeArray{
public:
    SafeArray(int maximun);
    ~SafeArray();
    bool check(int n);
    void clone(int n,int item);
private:
    int *data;
    int maximun=MAX;
};
#endif // SAFEARRAY_H
