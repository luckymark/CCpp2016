//
//  node.cpp
//  tree
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include "node.hpp"

Node::Node(int value){
    childs = new Node *[MAX_CHILD_SIZE];
    data = value;
    count = 0;
}

Node::~Node(){
    
}

void Node::append(Node * child){
    if(count >= MAX_CHILD_SIZE){
        expand();
    }
    childs[count] = child;
    childs[count]->parent = this;
    count ++;
}

int Node::childnum(){
    return count;
}

int Node::countAllNodes(){
    int result = 0;
    result = childnum();
    for(int i=0; i<count; i++){
        result += childs[i]->childnum();
    }
    return result;
}

void Node::expand(){
    Node * tmp_childs[count-1];
    for(int i=0; i<count; i++){
        tmp_childs[i] = childs[i];
    }
    childs = new Node *[count + MAX_CHILD_SIZE];
    for(int i=0; i<count; i++){
        childs[i] = tmp_childs[i];
    }
}

int Node::getThis(){
    return data;
}

int Node::getParent(){
    if(parent == NULL){
        return data;
    }
    return parent->getThis();
}

