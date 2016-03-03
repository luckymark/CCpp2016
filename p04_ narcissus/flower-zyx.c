#include<stdio.h>

int main(void) {
	int flower, a, b, c,sum;

	for (flower = 100; flower < 1000; flower++){
		a = flower / 100;
		b = (flower - 100 * a) / 10;
		c = flower - 100 * a - 10 * b;
		sum = a*a*a + b*b*b + c*c*c;
		if (flower == sum){
			printf("%d\n", flower);
			continue;
		}
	}
	return 0;
}