#include "SafeArray.hpp"

#include <assert.h>
int SafeArray::size(){
	return Size;
}
int& SafeArray::at(int pos){
	assert(pos <= Size);
	return data[pos];
}