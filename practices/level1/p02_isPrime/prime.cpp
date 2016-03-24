#include<stdio.h>
#include<windows.h>
int main()
{
	int a, b, c, i;
	c = 1;
	scanf_s("%d", &a);
	if (a == 2&&a==3)
		printf("YES");
	else {
		for (i = 2; i*i <= a; i++) {
			b = a%i;
			if (b == 0)
			{
				c = 0;
				break;
			}
			else
				c = 1;
		}
		if (c == 1)
			printf("YES");
		else
			printf("NO");
		Sleep(1000);
	}
	return 0;
}