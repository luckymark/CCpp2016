// Level0_C1.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <math.h>

void title();
void chooseMode();
void finish();
void judge1();
void judge2();
void judge3();
void findBiggest1();
void findBiggest2();
void findBiggest3();

int main()
{
	title();	
	return 0;
}

void title() {
	printf("你想要做什么？请输入序号\n");
	printf("1.判断数的正负、判断是否为偶数  2.判断一个数是否是13的倍数  3.判断闰年\n");
	printf("4.从2个整数中，找出最大的那个数  5.从3个整数中，找出最大的那个数  6.从n个整数中，找出最大的那个数\n");
	chooseMode();
}

void finish() {
	printf("\n判断完毕，现返回功能选择：\n");
	title();
}

void chooseMode() {
	int mode;
	scanf_s("%d", &mode);
	switch (mode)
	{
	case 1:
		judge1();
		break;
	case 2:
		judge2();
		break;
	case 3:
		judge3();
		break;
	case 4:
		findBiggest1();
		break;
	case 5:
		findBiggest2();
		break;
	case 6:
		findBiggest3();
		break;
	default:
		break;
	}
}


void judge1() {
	int num;
	printf("请输入数字：\n");
	scanf_s("%d", &num);
	if (abs(num) == num )
	{
		printf("%d是正数,",num);
	}
	else
	{
		printf("%d是负数，", num);
	}
	if (num % 2 == 0)
	{
		printf("是偶数\n");
	}
	else
	{
		printf("是奇数\n");
	}
	finish();
}

void judge2() {
	int num;
	printf("请输入数字：\n");
	scanf_s("%d", &num);
	if (0 == num % 13) {
		printf("%d是13的倍数\n",num);
	}
	else
	{
		printf("%d不是13的倍数\n",num);
	}
	finish();
}

void judge3() {
	int num;
	printf("请输入年份：\n");
	scanf_s("%d", &num);
	if (0 == num % 4 && 0 != num%100) {
		printf("%d是闰年\n", num);
	}
	else if (0 == num % 400){
		printf("%d是闰年\n", num);
	}
	else
	{
		printf("%d不是闰年\n", num);
	}
	finish();
}

void findBiggest1() {
	int num1, num2;
	printf("请输入数字1:");
	scanf_s("%d", &num1);
	printf("请输入数字2:");
	scanf_s("%d", &num2);
	printf("%d是最大的数\n", num1 > num2 ? num1:num2);
	finish();
}

void findBiggest2() {
	int num1, num2,num3;
	printf("请输入数字1:");
	scanf_s("%d", &num1);
	printf("请输入数字2:");
	scanf_s("%d", &num2);
	printf("请输入数字3:");
	scanf_s("%d", &num3);
	printf("%d是最大的数\n", num1 > num2 ? (num1 > num3 ? num1 : num3): (num2 > num3 ? num2 : num3));
	finish();
}

void findBiggest3() {
	int numTotal;
	printf("请输入数字的总个数：");
	scanf_s("%d", &numTotal);
	int *p = new int[numTotal];
	for (int i = 0; i < numTotal; i++)
	{
		printf("请输入第%d个数：",i + 1);
		scanf_s("%d", &(p[i]));
	}
	for (int i = 1;i < numTotal;i++) {
		if (p[0] < p[i]) {
			int temp = p[0];
			p[0] = p[i];
			p[i] = temp;
		}
	}
	printf("%d是最大的数\n", p[0]);
	delete[] p;
	finish();
}
