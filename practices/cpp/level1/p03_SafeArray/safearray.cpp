#include"safearray.h"
void Safearray::putin(int item) {
    data[i] = item;
    i++;
}
bool Safearray::safe(int item) {
    return i <= item;
}
