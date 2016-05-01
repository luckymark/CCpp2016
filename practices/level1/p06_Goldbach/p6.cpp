#include<stdio.h>
int show(int n);
int main(){
	int primelist[25];
	int delt, a1, a2, n = 1;
	int i = 1;
	int yee = 0;
	while (++n <= 100){
		if (show(n))
			primelist[i++] = n;

	}
	for (int a = 4; a <= 100; a += 2){
		yee = 0;
		for (a1 = 0; a1 < 25; a1++){
			delt = a - primelist[a1];
			for (a2 = 0; a2 < 25; a2++)
				if (primelist[a2] == delt)
				{
					printf("%d+%d=%d\n", primelist[a1], primelist[a2], a);
					yee = 1;
					break;
				}
			if (yee)
				break;
		}
	}
	return 0;
}
int show(int n){
	int ye = 1;
	for (int q = 2; q*q <= n; q++){
		if (n%q == 0)
		{
			ye = 0;
			break;
		}
	}
	if (ye)
		return 1;
	else
		return 0;
}