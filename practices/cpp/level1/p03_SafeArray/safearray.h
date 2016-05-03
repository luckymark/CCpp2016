#ifndef queque_h
#define queque_h
class SafeArray{
public:
    SafeArray(int capility);
    void getIn(int p,int a);
    int getOut(int p);
private:
    int all;
    int *data;
};
#endif
