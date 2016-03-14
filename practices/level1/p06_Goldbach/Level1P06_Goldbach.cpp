// Level1P06_Goldbach.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>

int isPrime(int num);
void findTwoPrime(int num);

int main()
{	
	int max = 100;
	for (int i = 4; i <= max; i+=2)
	{
		findTwoPrime(i);
	}
    return 0;
}

int isPrime(int num) {
	for (int i = 2; i*i <= num; i++)
	{
		if (num%i == 0) {
			return 0;
		}
	}
	return 1;
}

void findTwoPrime(int num) {
	for (int i = 2; i <= num/2; i++)
	{
		if (isPrime(i) && isPrime(num - i)) {
			printf("%d = %d + %d\n", num, i, num - i);
			break;
		}
	}
}
