#include <iostream>
using namespace std;

struct node
{
	float data;
	node *next;
};

node *head = NULL, *p, *q = NULL, *t = NULL;
int length;

void input();
void output();
void Reverse();
void FindFive();

int main() {
	input();
	output();
	cout << endl;
	FindFive();
	Reverse();
	output();

	system("pause");
	return 0;
}
void FindFive() {
	int Fin = 0, FinTwo = 0;;
	int count = 0;
	node *t = head;
	while (t != NULL) {
		Fin++;
		if (t->data == 5 && (count == 1)) {
			break;
		}
		else if (t->data == 5) {
			count++;
			FinTwo = Fin;
		}
		t = t->next;
	}
	if (count == 1) {
		cout << FinTwo << ' ' << Fin << endl;
	}
	else if (FinTwo != 0) {
		cout << FinTwo << endl;
	}
	else {
		cout << "cannot found five" << endl;
	}
}

void Reverse() {
	struct node *pre = NULL, *next = NULL;
	next = head->next;
	while (head->next != NULL) {
		head->next = pre;
		pre = head;
		head = next;
		next = head->next;
	}
	head->next = pre;
}

void input() {
	float input;
	int  otmp;

	cin >> length;

	for (otmp = 0; otmp <= length - 1; otmp++) {
		cin >> input;

		p = (node *)malloc(sizeof(node));
		p->data = input;
		p->next = NULL;
		if (head == NULL) {
			head = p;
		}
		else {
			q->next = p;
		}
		q = p;
	}
}

void output() {
	node *t = head;
	while (t != NULL) {
		cout << t->data << ' ';
		t = t->next;
	}
}