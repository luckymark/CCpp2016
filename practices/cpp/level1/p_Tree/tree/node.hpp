//
//  node.hpp
//  tree
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#ifndef node_hpp
#define node_hpp
#define NULL 0
#define MAX_CHILD_SIZE 16
#include <stdio.h>

class Node
{
public:
    Node(int value);
    ~Node();
    void append(Node * child);
    int countAllNodes();
    int getParent();
private:
    void expand();
    int childnum();
    int getThis();
    Node *parent = NULL;
    int data;
    int count;
    Node **childs;
};

#endif /* node_hpp */
