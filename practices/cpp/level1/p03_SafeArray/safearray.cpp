#include"safearray.h"
void safearray::putin(int item) {
	data[i] = item;
	i++;
}
bool safearray::safe(int item) {
	return i <= item;
}