#include<iostream>
#include<string>
#include"IntArray.h"

using namespace std;

int main()
{
	IntArray<float> arr(10);
	arr.setArray(1, 10.454);
	arr.getArray(1);
	arr.getArray(10);
	arr.getArray(13);
	system("pause");
	return 0;
}
