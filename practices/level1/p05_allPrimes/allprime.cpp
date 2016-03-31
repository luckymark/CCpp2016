#include<stdio.h>
#include<time.h>
int main()
{
	int q, t;
	q = clock();
	int b=0, c;
	for (int i = 2; i < 1000; i++)
	{
		if (i==2||i==3)
		{
			printf("%d ", i);
		}
		else
		{
			for (int j = 2; j * j <= i ; j++)
			{
				if (i%j == 0) {
					b = 0;
					break;
				}
				else
				{
					b = 1;
				}
			}
			if (b==1)
			{
				printf("%d ", i);
			}
		}
	}
	t = clock();
	printf("%d ms", t - q);
	getchar();
	return 0;
}