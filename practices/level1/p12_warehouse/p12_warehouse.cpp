#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

struct node
{
	int count;
	string name;
	node *next;
};
bool isExit = false;
struct node *head = NULL, *p, *q = NULL, *t = NULL;

void fileInputAndDo();
void showAll();
void inStorge();
void outStorge();
void exitAndSave();
void switchFunction(char dir);
void firstPage();

int main() {
	fileInputAndDo();
	return 0;
}

void findStringAndChange(string tmp, int add) {
	node *t = head;
	while (t != NULL) {
		if (t->name == tmp) {
			t->count += add;
			break;
		}
		else {

		}
		t = t->next;
	}
}
void firstPage() {
	system("cls");
	cout << "s. Show All" << endl;
	cout << "i. Input Storge" << endl;
	cout << "o. Output Storge" << endl;
	cout << "e. Exit" << endl;

}
void fileInputAndDo() {
	fstream fin;
	fin.open("storge.sto", ios_base::in);
	string name;
	int sum;
	while (1) {
		fin >> name >> sum;
		if (fin.eof()) {
			break;
		}
		p = new node;
		p->name = name;
		p->count = sum;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		}
		else {
			q->next = p;
		}
		q = p;

	}

	firstPage();
	char dir;
	while (!isExit) {
		if (_kbhit() != 0) {
			dir = _getch();
			if (dir == 's' || dir == 'i' || dir == 'o' || dir == 'e' || dir == 'r') {
				switchFunction(dir);
			}
		}
	}
}

void switchFunction(char dir) {
	switch (dir) {
	case 's': {
		showAll();
		break;
	}
	case 'i': {
		inStorge();
		break;
	}
	case 'o': {
		outStorge();
		break;
	}
	case 'e': {
		exitAndSave();
		break;
	}
	case 'r': {
		firstPage();
		break;
	}
	default: {
		break;
	}
	}
}

void showAll() {
	system("cls");
	string Name;
	node *t = head;
	while (t != NULL) {
		cout << t->name << "-------" << t->count << endl;
		t = t->next;
	}
	cout << "r. return to first page" << endl;
	cout << "i. Input Storge" << endl;
	cout << "o. Output Storge" << endl;
	cout << "e. Exit" << endl;
}

void inStorge() {
	system("cls");
	cout << "please input the name and the add num of your items(exit to more function)" << endl;
	string name;
	int num;
	cin >> name;
	while (name != "exit") {
		cin >> num;
		node *t = head;
		while (t != NULL) {
			if (t->name == name) {
				t->count += num;
				break;
			}
			else if (t->next == NULL) {
				p = new node;
				p->name = name;
				p->count = num;
				p->next = NULL;
				t->next = p;
				break;
			}
			t = t->next;
		}
		cin >> name;
	}
	cout << "function inStorge" << endl;
	cout << "r. return to first page" << endl;
	cout << "s. showAll" << endl;
	cout << "o. Output Storge" << endl;
	cout << "e. Exit" << endl;

}

void outStorge() {
	system("cls");
	cout << "please input the name and the deleted num of your items(exit to more function)" << endl;
	string name;
	int num;
	cin >> name;
	while (name != "exit") {
		node *t = head;
		q = t;
		while (t != NULL) {
			if (t->name == name) {
				cin >> num;
				if (t->count - num < 0) {
					cout << "no enouge storge to export!" << endl;
				}
				else {
					t->count -= num;
				}

				if (t->count == 0) {//node which count==0 would be deleted to free memory and storge!
					if (t->next != NULL) {
						if (q == head) {
							head = t->next;
						}
						else {
							q->next = t->next;
						}
					}
					else {
						q->next = NULL;
					}
					free(t);
				}
				break;
			}
			if (t->next == NULL) {
				cout << "There have no such item which was called " << name << endl;
			}
			q = t;
			t = t->next;
		}
		cin >> name;
	}
	cout << "function outStorge" << endl;
	cout << "r. return to first page" << endl;
	cout << "s. showAll" << endl;
	cout << "i. Input Storge" << endl;
	cout << "e. Exit" << endl;

}

void exitAndSave() {
	system("cls");
	cout << "writing files,please don't close the window" << endl;
	fstream fout;
	fout.open("storge.sto", ios_base::out);
	t = head;
	while (t != NULL) {
		fout << t->name << ' ' << t->count << endl;
		t = t->next;
	}
	fout.close();
	isExit = true;
	cout << "save finished!";
}