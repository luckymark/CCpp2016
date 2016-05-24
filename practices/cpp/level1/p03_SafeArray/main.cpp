#include <iostream>
#include "SafeArray.h"
int main()
{
	SafeArray a(100);
	a.in(30,17);
	a.in(15,19);
	a.in(99,90);
	printf("%d\n",a.out(30));
	printf("%d\n",a.out(15));
	printf("%d\n",a.out(110));
	return 0;
}
