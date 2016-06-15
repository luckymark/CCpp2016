#include <bits/stdc++.h>
#include "Stack.hpp"
using namespace std;
int main(){
	Stack s(100);
	for(int i=1;i<=10;++i){
		s.push(i);
	}
	while(!s.empty()){
		cout << s.top() << endl;
		s.pop();
	}
	return 0;
}