#ifndef SAFE_ARRAY_HPP__
#define SAFE_ARRAY_HPP__
#define MAX_SIZE 5

template <class data_type>
class SafeArray {
private:
    data_type m_array[MAX_SIZE];
    int m_size = MAX_SIZE;
public:
    data_type &operator[](int index);
};

#endif
