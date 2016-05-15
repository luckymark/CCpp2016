#include<iostream>
#include<cstdio>
#include<Windows.h>

using namespace std;

char* encrypt(char a[]);
char* decrypt(char b[]);
char buffer[1000];

int main()
{
	cin >> buffer;
	cout << encrypt(buffer) <<endl;
	cout << decrypt(buffer) << endl;
	Sleep(1000);
	return 0;
}

char* encrypt(char a[]) {
	for (int i = 0; i < 1000; i++)
	{
		if (a[i] == '\0')
		{
			break;
		}
		a[i] = a[i] + 1;
	}
	return a;
}
char* decrypt(char b[]) {
	for (int i = 0; i < 1000; i++)
	{
		if (b[i] == '\0')
		{
			break;
		}
		b[i] = b[i] - 1;
	}
	return b;
}