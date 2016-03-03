//By Eric 2016-03-02
//p03_Diophantus
#include <stdio.h>
#include <math.h>
//请问老师，比较浮点数的精度一般设为多少？
#define EPSILON 0.01
int main(void)
{
	double age;

	for (age = 0.0; fabs(age / 2 - ((age - 4) - (age / 6 + age / 12 + age / 7 + 5))) > EPSILON; age++)
		;//空语句
	printf("%.0lf", age - 4);

	return 0;
}