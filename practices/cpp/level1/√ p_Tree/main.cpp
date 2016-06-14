//
// Created by Administrator on 2016/6/9.
//

#include <iostream>
#include "Node.hpp"
#include <list>
void append(Node);//添加Node为父节点的节点
void showChild();
std::list<Node> treeNode;
int main() {
    Node head(0,1,-1);
    treeNode.push_back(head);
}

void append(Node) {
    int data;
    std::cin>>data;
    int mark;
    std::cin>>mark;
    int parent;
    std::cin>>parent;
    Node node(data,mark,parent);
    treeNode.push_back(node);
}

void showChild(Node node){
    std::list<int> Child;
    int markParent=node.getMark();
    Child.push_back(markParent);
    for(Node &s:treeNode){
        int parent=s.getParent();
        for(int &r : Child){
            if(parent==r){
                Child.push_back(s.getMark());
            }
        }
    }
}