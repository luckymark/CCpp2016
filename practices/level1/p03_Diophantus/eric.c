//By Eric 2016-03-02
//p03_Diophantus
#include <stdio.h>
#include <math.h>
//������ʦ���Ƚϸ������ľ���һ����Ϊ���٣�
#define EPSILON 0.01
int main(void)
{
	double age;

	for (age = 0.0; fabs(age / 2 - ((age - 4) - (age / 6 + age / 12 + age / 7 + 5))) > EPSILON; age++)
		;//�����
	printf("%.0lf", age - 4);

	return 0;
}