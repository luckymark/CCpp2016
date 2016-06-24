// ConsoleApplication44.cpp : 定义控制台应用程序的入口点。
//
#include<stdio.h>	
#include<stdlib.h>
#include<math.h>
#define double_len_of_console 158
int main(){
	for (int i = 1; i <= double_len_of_console; i++){
		printf("a");
		system("cls");
		for (int j = 1; j <= (79 - abs(79 - i)); j++)
			printf(" ");
	}

	return 0;
}

