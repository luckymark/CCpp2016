#include<stdio.h>
int main() {
	int n, yes = 1;
	scanf("%d", &n);
	for (int q = 2; q*q <= n; q++) {
		if (n%q == 0)
		{
			yes = 0;
			break;
		}
	}
	if (yes == 1)
		printf("isprime\n");
	else
		printf(":(\n");
	return 0;

}

