// Level1P02_IsPrime.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>

int isPrime(int num);

int main()
{
	printf("������һ��������");
	int num;
	scanf_s("%d", &num);
	if (isPrime(num) && num != 1) {
		printf("%d��һ������\n", num);
	}
	else
	{
		printf("%d����һ������\n", num);
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
