#include<stdio.h>
int main()
{
	int ans[25];
	ans[0] = 2;
	ans[1] = 3;
	int i, j = 2, m, l;
	int a, b = 0;
	for (i = 2; i < 100; i++)
	{
		if (i == 2 || i == 3);
		else
		{
			for (a = 2; a * a <= i; a++)
			{
				if (i%a == 0) {
					b = 0;
					break;
				}
				else
				{
					b = 1;
				}
			}
			if (b == 1)
			{
				ans[j] = i;
				j++;
			}
		}
	}/*
	for (int d = 0; d < j; d++) {
		printf("%d ", ans[d]);
	}
	printf("\n %d", j);*/
	for (int k = 4; k < 101; k++)
	{
		if (k % 2 == 0)
		{
			for (l = 0; l < j; l++)
			{
				for (m = 0; m < j; m++)
				{
					if (k == ans[l] + ans[m])
					{
						printf("%d=%d+%d\n", k, ans[l], ans[m]);
						break;
					}
					else
						if (ans[m] >= k)
							break;
				}
				if (k == ans[l] + ans[m])
					break;
				else
					if (ans[l] >= k)
					{
						break;
					}
			}
		}
	}
	getchar();
	return 0;
}