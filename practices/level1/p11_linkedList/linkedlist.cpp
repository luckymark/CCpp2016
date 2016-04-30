#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	typedef struct Node {
		int num;
		int data;
		Node* next;
	}Node;
	Node node;
	node.num = 1;
	Node* p = &node;
	cout << "Please input intger, end with negetive number." << endl;
	while (p != NULL) {
		cin >> p->data;
		if (p->data < 0)
		{
			break;
		}
		p->next = new Node{};
		p->next->num = p->num + 1;
		p = p->next;
	}
	int length = p->num;
	int record = length - 1;
	Node* q = &node;
	int temp;
	
	while (1)
	{
		p = &node;
		for (size_t i = 0; i < length-2; i++)
		{
			p = p->next;
		}
		if (p->num <= q->num)
		{
			break;
		}
		else
		{
			temp = p->data;
			p->data = q->data;
			q->data = temp;
			q = q->next;
			length--;
		}
	}
	p = &node;
	int first = 0;
	int second = 0;
	for (size_t i = 0; i < record; i++)
	{
		if (p->data == 5)
		{
			first = p->num;
			cout << "The first '5' is on:" << first << endl;
			p = p->next;
			for (size_t j = 0; j < record-first; j++)
			{
				if (p->data == 5)
				{
					second = p->num;
					cout << "The second '5' is on:" << second << endl;
					break;
				}
				p = p->next;
			}
			if (second == 0)
			{
				cout << "The second '5' is on:" << -1 << endl;
			}
			break;
		}
		p = p->next;
	}
	if (first == 0)
	{
		cout << "The first '5' is on:" << -1 << endl;
	}
	system("pause");
	return 0;
}