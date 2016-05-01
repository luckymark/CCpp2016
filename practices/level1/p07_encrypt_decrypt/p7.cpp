#include"stdafx.h"
#include<stdio.h>
#include<string.h>
char s[100];
void encrypt(char s[], int n);
void decrypt(char s[], int n);
int main() {
	printf("Input the string\n");
	scanf("%s",s);
	encrypt(s, strlen(s));
	printf("%s", s);
	decrypt(s, strlen(s));
	printf("\n%s", s);
}
void encrypt(char s[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (s[i] != 127)
			s[i] += 1;
		else
			s[i] = '!';
	}
}
void decrypt(char s[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		if (s[i] != '!')
			s[i] -= 1;
		else
			s[i] = 127;
	}
}