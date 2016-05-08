//============================================================================
// Name        : Level1P07_encrypt_decrypt.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;


void showTitle();
void encrypt(int length,const char *p);
void decrypt(int length,const char *p);

int main() {

	showTitle();
	return 0;
}

void showTitle(){
	cout << "输入要操作的句子：" << endl;
	string tempWords;
	cin >> tempWords;
	const char *words = tempWords.data();
	int length = strlen(words);
	cout << "请选择：	1.加密	2.解密"	<< endl;
	int choice;
	cin >> choice;
	switch(choice){
	case 1:
		encrypt(length,words);
		break;
	case 2:
		decrypt(length,words);
		break;
	default:
		break;
	}

}

void encrypt(int length,const char *p){
	cout << "加密内容：";
	for(int i = 0;i < length;i++){
		cout << char(p[i] + 1);
	}
	cout << "\n加密完毕" << endl;
}

void decrypt(int length,const char*p){
	cout << "解密内容：";
	for(int i = 0;i < length;i++){
		cout << char(p[i] - 1);
	}
	cout << "\n解密完毕" << endl;
}




