//Eric 2016-03-05
//p07_encrypt_decrypt
//��Ҫ���ܽ��ܵ��ļ�����Ϊin.txt ������out.txt
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int fshowGetOrder(void);
char fencrypt(char operatorChar);
char fdecrypt(char operatorChar);
void fstartOpeate(int enDeFlag);	//������
int main(void)
{
	fstartOpeate(fshowGetOrder());
	return 0;
}

int fshowGetOrder(void)
{
	int order;
	printf("1.Encrypt 2.Decrypt 3.Quit: ");
	while (scanf("%d", &order) == 1)
	{
		//���봦��
		switch (order)
		{
		case 1:
		case 2:
		case 3:
			return order;
		default:
			printf("Please Enter the number among 1 2 3:");
		}
	}
}
void fstartOpeate(int enDeFlag)
{
	FILE *pointerFileInput;
	char tempInput;
	switch (enDeFlag)
	{
	case 1:
	case 2:
		pointerFileInput = fopen("in.txt", "r");
		//�ж�in.txt�Ĵ���
		if (pointerFileInput == NULL)
		{
			printf("Error : File error.");
			return;
		}
		fclose(pointerFileInput);

		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
		while ((tempInput = getchar()) != EOF)
		{
			//ѡ�����ܽ���
			switch (enDeFlag)
			{
			case 1:
				printf("%c", fencrypt(tempInput));
				break;
			case 2:
				printf("%c", fdecrypt(tempInput));
				break;
			default:
				printf("Error : ed_switch error");
				return;
			}
	case 3:
		printf("Done.");
		return;
	default:
		printf("ERROR : Wrong Command.\n");
		return;
		}
	}
}
char fencrypt(char operatorChar)
{
	return operatorChar - 1;
}
char fdecrypt(char operatorChar)
{
	return operatorChar + 1;
}