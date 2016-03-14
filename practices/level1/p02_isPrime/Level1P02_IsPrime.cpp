// Level1P02_IsPrime.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>

int isPrime(int num);

int main()
{
	printf("请输入一个正数：");
	int num;
	scanf_s("%d", &num);
	if (isPrime(num) && num != 1) {
		printf("%d是一个质数\n", num);
	}
	else
	{
		printf("%d不是一个质数\n", num);
	}
    return 0;
}

int isPrime(int num) {
	for (int i = 2; i*i < num; i++)
	{
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
