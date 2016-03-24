#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void  encryptstr(char *str);
void reencryptstr(char *str);
int main()
{
	int i = 1;
	char c;
	char *temp, *str = "\0";
	c = getchar();
	while (c != '\n')
	{
		temp = str;
		str = (char *)malloc((i + 1)*sizeof(char));
		str[0] = '\0';
		strcat(str, temp);
		str[i - 1] = c;
		str[i] = '\0';
		if (i > 1)
		{
			free(temp);
		}
		i++;
		c = getchar();
	}
	encryptstr(str);
	printf("%s\n", str);
	reencryptstr(str);
	printf("%s\n", str);
	system("pause");
	free(str);
}

void encryptstr(char * str)
{
	int n ;
	for (n = 0; str[n] != '\0'; n++)
	{
		if (n % 2 == 0)
		{
			str[n] -= '1';
		}
		else
		{
			str[n] -= '2';
		}
	}
}

void reencryptstr(char * str)
{
	int n;
	for (n = 0; str[n] != '\0'; n++)
	{
		if (n % 2 == 0)
		{
			str[n] += '1';
		}
		else
		{
			str[n] += '2';
		}
	}
}
