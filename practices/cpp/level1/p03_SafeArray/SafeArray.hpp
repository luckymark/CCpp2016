#ifndef _SAFEARRAY_HPP
#define _SAFEARRAY_HPP

class SafeArray{
public:
	SafeArray(int maxSize){
		data = new int[maxSize];
		Size = maxSize;
	}
	~SafeArray(){
		delete [] data;
	}
	int size();
	int& at(int pos);
private:
	int *data,Size;
};
#endif