#include<stdio.h>
#include<Windows.h>
int main()
{
	for (int i = 15; i < 100; i++)
		if (i % (12 * 7) == 0)
			if ((i / 2) == i - (i / 6) - (i / 12) - (i / 7) - 5 - 4)
				printf("%d\n", i);
	Sleep(1000);
	return 0;
}