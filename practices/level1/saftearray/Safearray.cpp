#include "stdafx.h"
#include "Safearray.h"
#include<iostream>
using namespace std;
bool Safearray::in(void) {
	return(now < 100);
}
void Safearray::output(int n) {
	if (n<100)
		cout << "Too muck" << endl;
	else
		cout << data[n];
}
void Safearray::input(int n){
	if (!in())
		cout << "Too much" << endl;
	else
		data[now] = n;
	now++;
}