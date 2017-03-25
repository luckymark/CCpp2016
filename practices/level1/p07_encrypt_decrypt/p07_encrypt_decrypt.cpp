// p07_encrypt_decrypt.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

const char lower[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
const char upper[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
string st;
int len;

void encipher()
{
	for (int i = 0; i <= len-1; i++)
	{
		if (st[i]>='a' && st[i]<='z')
			st[i] = lower[(st[i] - 93) % 26];
		if (st[i]>='A' && st[i]<='Z')
			st[i] = upper[(st[i] - 61) % 26];
	}
}

void decrypt()
{
	for (int i = 0; i <= len - 1; i++)
	{
		if (st[i] >= 'a' && st[i] <= 'z')
			st[i] = lower[(st[i] -75) % 26];
		if (st[i] >= 'A' && st[i] <= 'Z')
			st[i] = upper[(st[i] -43) % 26];
	}
}
int main()
{
	
	cin >> st;
	len = st.size();
	encipher();
	cout << "���ܷ������ַ�����4λ" << endl;
	cout << "���ܣ�"<<st << endl;
	decrypt();
	cout <<"���ܣ�"<< st << endl;
	system("pause");
	return 0;
}

