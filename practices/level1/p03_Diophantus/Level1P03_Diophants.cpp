// Level1P03_Diophants.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <stdio.h>


int main()
{
	for (float age = 80; age < 1000; age++){
		if ((age * 51 / 84 - 4.0 - 5.0) == (age / 2)){
			printf("����ͼ��%d��\n",(int)age);
			break;
		}
		
	}
	return 0;
}

