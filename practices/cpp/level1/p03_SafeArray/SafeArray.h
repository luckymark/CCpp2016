#ifndef SAFEARRAY_SAFEARRAY_H
#define SAFEARRAY_SAFEARRAY_H
#include <assert.h>
template <class T,int capability>
class SafeArray {
private:
    T array[capability] = {0};
public:
    T &operator[](const int &position) {
        assert(position >= 0 && position < capability);
        return array[position];
    }
};


#endif //SAFEARRAY_SAFEARRAY_H
