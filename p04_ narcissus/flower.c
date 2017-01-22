#include<stdio.h>

int main(void) {
	for (int flower = 100; flower < 1000; flower++){
		int a = flower / 100;
		int b = (flower - 100 * a) / 10;
		int c = flower - 100 * a - 10 * b;
		int sum = a*a*a + b*b*b + c*c*c;
		if (flower == sum){
			printf("%d\n", flower);
		}
	}
	return 0;
}