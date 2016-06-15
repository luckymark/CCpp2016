//
// Created by wxdao on 16-6-15.
//

#ifndef BORING_SAFEARRAY_H
#define BORING_SAFEARRAY_H

#include <cstddef>
#include <stdexcept>

template<class T>
class SafeArray {
private:
    T *array;
    std::size_t size;
public:
    SafeArray(std::size_t size) : size(size) {
        array = new T[size];
    }

    ~SafeArray() {
        delete array;
    }

    T &get(std::size_t pos) {
        if (pos >= 0 && pos < size) {
            return array[pos];
        }
        throw std::out_of_range("out of range");
    }

    void set(std::size_t pos, T value) {
        if (pos >= 0 && pos < size) {
            array[pos] = value;
        }
        throw std::out_of_range("out of range");
    }

    T &operator[](std::size_t pos) {
        return get(pos);
    }
};


#endif //BORING_SAFEARRAY_H
