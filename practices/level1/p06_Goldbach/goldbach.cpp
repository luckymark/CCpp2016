#include<stdio.h>
int main()
{
	int ans[25];
	ans[0] = 2;
	ans[1] = 3;
	int k = 2, m, l;
	int b = 0;
	for (int i = 2; i < 100; i++)
	{
		if (i == 2 || i == 3);
		else
		{
			for (j = 2; j * j <= i; j++)
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
			if (b == 1)
			{
				ans[k] = i;
				k++;
			}
		}
	}
	for (int i = 4; i < 101; i++)
	{
		if (i % 2 == 0)
		{
			for (l = 0; l < k; l++)
			{
				for (m = 0; m < k; m++)
				{
					if (i == ans[l] + ans[m])
					{
						printf("%d=%d+%d\n", i, ans[l], ans[m]);
						break;
					}
					else
						if (ans[m] >= i)
							break;
				}
				if (i == ans[l] + ans[m])
					break;
				else
					if (ans[l] >= i)
					{
						break;
					}
			}
		}
	}
	getchar();
	return 0;
}