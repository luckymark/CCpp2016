#include "Tree.h"

Tree::Tree(int root, int size):root(root),size(size)
{
	edgeNum = 0;
	fir = new int[size];
	Next = new int[size];
	End = new int[size];
	value = new int[size];
	father = new int[size];
	memset(fir, 0, sizeof(int)*size);
	memset(Next, 0, sizeof(int)*size);
	memset(End, 0, sizeof(int)*size);
	memset(value, 0, sizeof(int)*size);
	memset(father, 0, sizeof(int)*size);
}

void Tree::append(int fa, int son, int _value)
{
	Next[++edgeNum] = fir[fa];
	fir[fa] = edgeNum;
	End[edgeNum] = son;
	value[son] = _value;
	father[son] = fa;
}

int Tree::getFather(int index)
{
	return father[index];
}

int Tree::calSonIndex(int index)
{
	nodeNum = 0;
	DFS(index);
	return nodeNum;
}

void Tree::DFS(int index)
{
	++nodeNum;
	//printf("index=%d\n", index);
	for (int u = fir[index];u;u = Next[u])
		DFS(End[u]);
}
