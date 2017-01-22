#include <bits/stdc++.h>
#include "SafeArray.hpp"
using namespace std;

int main(){
	SafeArray arr(100);
	for(int i = 1; i <= 99 ; ++i){
		arr.at(i) = i;
	} // no problem

	cout << arr.at(99) << endl;
	arr.at(99) = 1;
	cout << arr.at(99) << endl;
	// modify value

	arr.at(100) = 0; // error

	return 0;
}