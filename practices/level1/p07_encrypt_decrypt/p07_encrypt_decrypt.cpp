#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <Windows.h>
using namespace std;

fstream fin, fout, passwordFile;
string stringTmpSave, finalResult = "";
char modeTurn;

void input();
char bitEncrypt(int ran, char bitChar);
void encrypt();
void decrypt();
void startIt();

int main() {
	input();
	startIt();
	system("pause");
	return 0;
}

void input() {
	fin.open("from.from", ios_base::in);
	modeTurn = 't';
	while (!(modeTurn == 'f' || modeTurn == 'c')) {
		cout << "do you want to input your data from file \"from.from\" or from console? (f/c): ";
		cin >> modeTurn;
	}

	if (modeTurn == 'f') {
		fin >> stringTmpSave;
	}
	else {
		cout << "Please input your content: ";
		cin >> stringTmpSave;
	}

	cout << endl;
	while (!(modeTurn == 'e' || modeTurn == 'd')) {
		cout << "do you want to encrypt or decrypt it?(e/d):  ";
		cin >> modeTurn;
	}

	fin.close();
}

char bitEncrypt(int ran, char bitChar) {
	char mix = (char)(127 - (int)bitChar - floor(sqrt(ran)));
	return mix;
}

void encrypt() {
	fout.open("to.to", ios_base::out);
	passwordFile.open("pas.p", ios_base::out);
	int length = stringTmpSave.length();
	srand((unsigned)GetTickCount64());
	for (int tmp = 0; tmp <= length - 1; tmp++) {
		int ran = (int)(32 * rand() / (RAND_MAX + 1.0));
		int RanInsCh = (int)(57 * rand() / (RAND_MAX + 1.0)) + 65;
		cout << ran;
		cout << (char)RanInsCh;
		passwordFile << ran;
		passwordFile << (char)RanInsCh;
		finalResult.push_back((char)bitEncrypt(ran, stringTmpSave[tmp]));
	}
	fout << finalResult;
	cout << endl;
	cout << finalResult;

	fout.close();
	passwordFile.close();
}

void decrypt() {
	cout << "you have to make sure that the file pas.p is already exist and contains the key" << endl;
	fout.open("to.to", ios_base::out);
	passwordFile.open("pas.p", ios_base::in);
	string key;
	passwordFile >> key;
	int length = key.length();
	int bit = 0, finkey = 0, fromP = 0;
	char bitkey = '0';
	for (int tmp = 0; tmp <= length - 1; tmp++) {
		bitkey = key[bit];
		if ((int)bitkey <= (int)'9' && (int)bitkey >= (int)'0') {
			finkey = 10 * finkey + (int)((int)bitkey - (int)'0');
		}
		else {

			char fin = bitEncrypt(finkey, stringTmpSave[fromP]);
			fout << fin;
			cout << fin;
			fromP++;
			finkey = 0;
		}
		bit++;
	}

	fout.close();
	passwordFile.close();

}
void startIt() {
	if (modeTurn == 'e') {
		encrypt();
	}
	else if (modeTurn == 'd') {
		decrypt();
	}
}