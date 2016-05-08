//============================================================================
// Name        : Level1P08_hanoi.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void hanoi(int n,char from,char by,char to);
void move(char from,char to);

int main() {

	hanoi(4,'A','B','C');
	return 0;
}

void hanoi(int n,char from,char by,char to){
	if(n == 1){
		move(from,to);
		return;
	}

	hanoi(n-1,from,to,by);
	move(from,to);
	hanoi(n-1,by,from,to);
}

void move(char from,char to){
	cout << from << "->" << to << endl;
}

