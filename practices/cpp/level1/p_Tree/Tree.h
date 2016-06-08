#pragma once

#include<iostream>
#include<vector>

class Tree
{
public:
	Tree();
	~Tree();
	int get_data();
	void set_data(int data);
	std::vector<Tree> &get_children();
	void newbranch(int data);
private:
	int data;
	std::vector<Tree> children;
};

Tree::Tree()
{
}

Tree::~Tree()
{
}

inline int Tree::get_data()
{
	return data;
}

inline void Tree::set_data(int data)
{
	Tree::data = data;
}

inline std::vector<Tree>& Tree::get_children()
{
	return children;
}

inline void Tree::newbranch(int data)
{
	children.push_back(*(new Tree));
	children.back().set_data(data);
}
