// Level1P05_allPrimes.cpp : 定义控制台应用程序的入口点。
//

#include <stido.h>


void findPrime(int max);
void printPrime();
int prime[10000] = { 2 };
int primeSum = 1;
void insertPrime(int flag,int num);

int main()
{
	findPrime(20000);
	printPrime();
    return 0;
}

void findPrime(int max) {
	for (int i = 3; i <= max; i+=2)
	{
		int flag = 1;
		for (int j = 0;i >= prime[j] * prime[j] && j < primeSum;j++) {
			if (i % prime[j] == 0) {				
				flag = 0;
				break;
				 
			}
			
		}
		insertPrime(flag, i);
	}
}

void printPrime() {
	printf("共有%d个质数：\n", primeSum);
	for (int i = 0; i < primeSum; i++)
	{
		printf("%d\n", prime[i]);
	}
}

void insertPrime(int flag,int num) {
	if (flag)
	{
		prime[primeSum] = num;
		primeSum++;
	}
}
