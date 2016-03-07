//by Eric 2016-03-02
//p02_isPrime
#include <stdio.h>

int main(void)
{
	unsigned int num;
	
	scanf("%u", &num);
	if (num == 1)
		printf("No");
	else
	{
		for (int count1 = 2; count1 <= (int) num / 2; count1++)
		{
			if (num % count1 == 0)
			{
				printf("No");
				return 0;
			}
		}
		printf("Yes");
	}

	return 0;
}