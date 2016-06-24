#include<stdio.h>
int main()
{
	int fa, so = 0;
	for (fa = 12;; fa += 12)
	{
		if (fa % 6 != 0 || fa % 7 != 0)
			continue;
		so = fa * 17 / 28 - 9;
		if (so == fa / 2)
		{
			printf("%d\n", fa);
			break;
		}

	}
	return 0;

}