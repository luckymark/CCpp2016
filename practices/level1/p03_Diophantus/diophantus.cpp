#include<stdio.h>
#include<Windows.h>
int main()
{
	int x;
	for (x = 15; x < 100; x++)
		if (x % (12 * 7) == 0)
			if ((x / 2) == x - (x / 6) - (x / 12) - (x / 7) - 5 - 4)
				printf("%d\n", x);
	Sleep(1000);
	return 0;
}