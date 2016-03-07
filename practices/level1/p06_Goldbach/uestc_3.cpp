
#include "math.h"
#include "iostream"

bool check(int v)
{
	int num_sqrt=(int)sqrt(v);
	for (int i = 2; i < num_sqrt; i++)
		if (v / i*i == v) return false;   //这一句是看v能否被i整除，素数只能被1和自身整除，如果这个判断成立，就返回false
	return true;
}

int main()
{
	for (int i = 2; i <= 100; i += 2)
	{
		for (int j = 1; j < i; j++)
		{
			if (check(j) && check(i - j)) break;  //找到都是质数的直接break
			
			if (j+1==i)  //遍历完了也找不到两个质数满足条件
			  printf("Nope\n");  //找不到，输出NOPE

		}
	}
	printf("Yes");
	system("pause");
	return 0;
}

