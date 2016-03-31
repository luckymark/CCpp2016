//Eric warehouse v2.0

#include "warehouse.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
#ifdef _DEBUG
	printf("warehouse v2.0\n");
#endif
	fstartWarehouse();
#ifdef _DEBUG
	system("pause");
#endif
}