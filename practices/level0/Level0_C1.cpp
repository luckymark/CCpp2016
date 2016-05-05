// Level0_C1.cpp : �������̨Ӧ�ó������ڵ㡣
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
	printf("����Ҫ��ʲô�����������\n");
	printf("1.�ж������������ж��Ƿ�Ϊż��  2.�ж�һ�����Ƿ���13�ı���  3.�ж�����\n");
	printf("4.��2�������У��ҳ������Ǹ���  5.��3�������У��ҳ������Ǹ���  6.��n�������У��ҳ������Ǹ���\n");
	chooseMode();
}

void finish() {
	printf("\n�ж���ϣ��ַ��ع���ѡ��\n");
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
	printf("���������֣�\n");
	scanf_s("%d", &num);
	if (abs(num) == num )
	{
		printf("%d������,",num);
	}
	else
	{
		printf("%d�Ǹ�����", num);
	}
	if (num % 2 == 0)
	{
		printf("��ż��\n");
	}
	else
	{
		printf("������\n");
	}
	finish();
}

void judge2() {
	int num;
	printf("���������֣�\n");
	scanf_s("%d", &num);
	if (0 == num % 13) {
		printf("%d��13�ı���\n",num);
	}
	else
	{
		printf("%d����13�ı���\n",num);
	}
	finish();
}

void judge3() {
	int num;
	printf("��������ݣ�\n");
	scanf_s("%d", &num);
	if (0 == num % 4 && 0 != num%100) {
		printf("%d������\n", num);
	}
	else if (0 == num % 400){
		printf("%d������\n", num);
	}
	else
	{
		printf("%d��������\n", num);
	}
	finish();
}

void findBiggest1() {
	int num1, num2;
	printf("����������1:");
	scanf_s("%d", &num1);
	printf("����������2:");
	scanf_s("%d", &num2);
	printf("%d��������\n", num1 > num2 ? num1:num2);
	finish();
}

void findBiggest2() {
	int num1, num2,num3;
	printf("����������1:");
	scanf_s("%d", &num1);
	printf("����������2:");
	scanf_s("%d", &num2);
	printf("����������3:");
	scanf_s("%d", &num3);
	printf("%d��������\n", num1 > num2 ? (num1 > num3 ? num1 : num3): (num2 > num3 ? num2 : num3));
	finish();
}

void findBiggest3() {
	int numTotal;
	printf("���������ֵ��ܸ�����");
	scanf_s("%d", &numTotal);
	int *p = new int[numTotal];
	for (int i = 0; i < numTotal; i++)
	{
		printf("�������%d������",i + 1);
		scanf_s("%d", &(p[i]));
	}
	for (int i = 1;i < numTotal;i++) {
		if (p[0] < p[i]) {
			int temp = p[0];
			p[0] = p[i];
			p[i] = temp;
		}
	}
	printf("%d��������\n", p[0]);
	delete[] p;
	finish();
}
