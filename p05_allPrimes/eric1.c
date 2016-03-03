//by Eric 2016-03-02
//p02_isPrime
#include <stdio.h>
#include <time.h>
#define MAX 1001
int main(void)
{
	int count1;

	printf("2\n");
	for (count1 = 3; count1 < MAX; count1 += 2)
	{
		for (int num = 3; num < count1 / 2; num++)
		{
			if (count1 % num == 0)
			{
				goto _break;
			}
		}
		printf("%d\n", count1);
	_break:
		;
	}

	printf("time:%f s", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}