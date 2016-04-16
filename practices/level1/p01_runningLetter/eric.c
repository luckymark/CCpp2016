//By Eric 2016-03-02
//p01_runningLetter
//Windows10 x64 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LENGTH 80
#define _WORD 'a'
int main(void)
{
	int count_location, count_blank;

	while (1)
	{
		for (count_location = 0; count_location < 2 * LENGTH; count_location++)
		{
			system("cls");
			for (count_blank = LENGTH; count_blank > abs(LENGTH - count_location); count_blank--)
			{
				printf(" ");
			}
			printf("%c", _WORD);
		}

	}

	return 0;
}