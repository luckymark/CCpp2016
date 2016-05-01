#include<stdio.h>
int show(int a);
int main(){
	int i;
	for (i = 100; i <= 999; i++)
	{
		if (show(i))
			printf("%d\n", i);
	}
	return 0;

}
int show(int a){
	int m, n, p;
	m = a % 10;
	n = (a / 10) % 10;
	p = (a / 100);
	if (m*m*m + n*n*n + p*p*p == a)
		return 1;
	else
		return 0;

}

