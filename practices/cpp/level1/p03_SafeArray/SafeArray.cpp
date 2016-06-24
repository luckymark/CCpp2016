#include "SafeArray.hpp"

template<class data_type>
data_type &SafeArray<data_type>::operator[](int index) {
    if (index < 0 || index >= m_size) {
        throw "Out Of Index!";
    }
    return m_array[index];
}
