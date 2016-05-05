// Level1P03_Diophants.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>


int main()
{
	for (float age = 80; age < 1000; age++){
		if ((age * 51 / 84 - 4.0 - 5.0) == (age / 2)){
			printf("丢翻图有%d岁\n",(int)age);
			break;
		}
		
	}
	return 0;
}

