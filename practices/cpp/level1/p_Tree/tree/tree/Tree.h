#pragma once
#include <memory>
class Tree
{
public:
	Tree(int root,int size =100);
	void append(int fa, int son, int _value);
	int getFather(int index);
	int calSonIndex(int index);
private:
	void DFS(int index);
	int root, size,edgeNum;
	int *fir, *Next, *End, *value, *father;
	int nodeNum;
};

