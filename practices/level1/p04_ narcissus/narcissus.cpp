#include<stdio.h>
#include<time.h>
int main()
{
	int q, t, i;
	q = clock();
	int h = 0, c;
	for (int i = 2; i < 1000; i++)
	{
		if (i == 2 || i == 3)
		{
			printf("%d ", i);
		}
		else
		{
			for (int j = 2; j * j <= i; j++)
			{
				if (i%j == 0) {
					h = 0;
					break;
				}
				else
				{
					h = 1;
				}
			}
			if (b == 1)
			{
				printf("%d ", i);
			}
		}
	}
	t = clock();
	printf("%d ms", t - q);
	system("pause");
	return 0;
}