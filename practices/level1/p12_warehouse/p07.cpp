#include<stdio.h>
#include<ctype.h>
#define KEY '&'
void encrypt()
{
	int orig_char,new_char;
	while((orig_char=getchar())!=EOF)
	{
		new_char=orig_char^KEY;
		if(isprint(orig_char)&&isprint(new_char))
		{
			putchar(new_char);
		}
		else
		{
			putchar(orig_char);
		}
	}
}
void decrypt()
{
	encrypt();
}

int main()
{
	int a;
	printf("please choose to encrypt or decrypt(1/2):");
	scanf("%d",&a);
	switch(a)
	{
		case 1:encrypt();
		break;
		case 2:decrypt();
		break;
	}
	return 0;
}