#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <Windows.h>
using namespace std;

fstream fin, fout, pasW;
string sta, fina = "";
char ModeTurn;

void ready();
char BitEn(int ran, char mw);
void en();
void de();
void StartIt();

int main() {
	ready();
	StartIt();
	system("pause");
	return 0;
}

void ready() {
	fin.open("from.from", ios_base::in);

	ModeTurn = 't';
	while (!(ModeTurn == 'f' || ModeTurn == 'c')) {
		cout << "do you want to input your data from file \"from.from\" or from console? (f/c): ";
		cin >> ModeTurn;
	}

	if (ModeTurn == 'f') {
		fin >> sta;
	}
	else {
		cout << "Please input your content: ";
		cin >> sta;
	}

	cout << endl;
	while (!(ModeTurn == 'e' || ModeTurn == 'd')) {
		cout << "do you want to encrypt or decrypt it?(e/d):  ";
		cin >> ModeTurn;
	}

	fin.close();
}

char BitEn(int ran, char mw) {
	char mix = (char)(127 - (int)mw - floor(sqrt(ran)));
	return mix;
}

void en() {
	fout.open("to.to", ios_base::out);
	pasW.open("pas.p", ios_base::out);
	int length = sta.length();
	srand((unsigned)GetTickCount64());
	for (int tmp = 0; tmp <= length - 1; tmp++) {
		int ran = (int)(32 * rand() / (RAND_MAX + 1.0));
		int RanInsCh = (int)(57 * rand() / (RAND_MAX + 1.0)) + 65;
		cout << ran;
		cout << (char)RanInsCh;
		pasW << ran;
		pasW << (char)RanInsCh;
		fina.push_back((char)BitEn(ran, sta[tmp]));
	}
	fout << fina;
	cout << endl;
	cout << fina;

	fout.close();
	pasW.close();
}

void de() {
	cout << "you have to make sure that the file pas.p is already exist and contains the key" << endl;
	fout.open("to.to", ios_base::out);
	pasW.open("pas.p", ios_base::in);
	string key;
	pasW >> key;
	int length = key.length();
	int bit = 0, finkey = 0, fromP = 0;
	char bitkey = '0';
	for (int tmp = 0; tmp <= length - 1; tmp++) {
		bitkey = key[bit];
		if ((int)bitkey <= (int)'9' && (int)bitkey >= (int)'0') {
			finkey = 10 * finkey + (int)((int)bitkey - (int)'0');
		}
		else {

			char fin = BitEn(finkey, sta[fromP]);
			fout << fin;
			cout << fin;
			fromP++;
			finkey = 0;
		}
		bit++;
	}

	fout.close();
	pasW.close();
}
void StartIt() {
	if (ModeTurn == 'e') {
		en();
	}
	else if (ModeTurn == 'd') {
		de();
	}
}