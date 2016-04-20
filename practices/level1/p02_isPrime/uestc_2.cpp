
#include <iostream>
#include <ctime>
using namespace std;

int n; //全局变量是为了在PowMod中取余用。

int PowMod(int r, int v)   //快速幂
{
	if (v == 1) return r;
	int num = PowMod(r, v >> 1);
	if ((v & 1) == 1)
		return (num*num*r) % n;
	if ((v & 1) == 0)
		return (num*num) % n;
}
int main()
{
	
	scanf_s("%d", &n);
	if (n<3) printf("No");
	srand(time(0));
	for (int i = 1; i <= 3; i++)
	{
		int r;
		do {
			r = rand() % n;
		    } while (r < 2);
		if (PowMod(r, n - 1) != 1) //费马小定理,筛法的时间复杂度大于费马小定理
		{
			printf("Not");
			return 0;
		}
		
	}
	printf("Yes");
    return 0;
}

