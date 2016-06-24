#include<iostream>
#include"Tree.h"

using namespace std;

void loop(int size, Tree *p);

int main()
{
	Tree *p;
	Tree tree;
	p = &tree;
	p->newbranch(10);
	p = &tree.get_children()[0];
	p->newbranch(100);
	int size = tree.get_children().size() + p->get_children().size();

	p = &tree;
	loop(size, p);
	cout << "the whole number of the tree is " << size << endl;
	system("pause");
	return 0;
}

void loop(int size, Tree *p)
{
	size += p->get_children().size();
	int num = p->get_children().size();
	if (num != 0)
	{
		for (size_t i = 0; i < num; i++)
		{
			loop(size, &(p->get_children()[i]));
		}
	}
	size += num;
}