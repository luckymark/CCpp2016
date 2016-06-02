//
//  main.cpp
//  tree
//
//  Created by Ferris on 16/6/1.
//  Copyright © 2016年 Ferris. All rights reserved.
//

#include <iostream>
#include "node.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    Node * root = new Node(100);
    Node * child1 = new Node(200);
    Node * child2 = new Node(300);
    Node * child1_1 = new Node(400);
    Node * child2_1 = new Node(500);
    Node * child2_2 = new Node(600);
    root->append(child1);
    root->append(child2);
    child1->append(child1_1);
    child2->append(child2_1);
    child2->append(child2_2);
    for(int i=0; i<=100; i++){
        Node * n = new Node(i);
        root->append(n);
    }
    cout << "The tree has " << root->countAllNodes() << " nodes." << endl;
    cout << "Node 2-2 has parent " << child2_2->getParent() << endl;
    return 0;
}
