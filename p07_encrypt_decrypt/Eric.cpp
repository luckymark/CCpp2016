//Eric 2016-03-05
//p07_encrypt_decrypt
//把要加密解密的文件命名为in.txt 结果在out.txt
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void encrypt(void);
void decrypt(void);

int main(void)
{
	int enDeFlag;
	printf("1.Encrypt 2.Decrypt : ");
	scanf("%d", &enDeFlag);
	//重定向输入输出
	freopen("out.txt", "w", stdout);
	freopen("in.txt", "r", stdin);

	//while (getchar() != '\n');
	if (enDeFlag == 1)
	{
		encrypt();
	}
	else
	{
		decrypt();
	}
	return 0;
}

void encrypt(void)
{
	char temp;
	int count1 = 1;
	while ((temp = getchar()) != EOF)
	{
		putchar(temp);
		srand(clock());
		for (int count2 = 0; count2 < count1; count2++)
		{
			putchar('a' + rand() % 24);
		}
		srand(count1);
		count1 = rand() % 10 + 1;
	}
}

void decrypt(void)
{
	int count1 = 1;
	char temp;
	while ((temp = getchar()) != EOF)
	{
		putchar(temp);
		for (int count2 = 0; count2 < count1; count2++)
		{
			getchar();
		}
		srand(count1);
		count1 = rand() % 10 + 1;
	}
}