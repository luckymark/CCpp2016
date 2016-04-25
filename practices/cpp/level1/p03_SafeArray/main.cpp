#include<iostream>
using namespace std;
#include"safearray.h"
int main() {
	safearray s(100);
	while (1) {
		if (!s.safe(100)) {
			s.putin(100);
		}
		else {
			cout << "overload"<<endl;
			break;
		}
	}
}