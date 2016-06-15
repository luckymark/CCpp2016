#include <iostream>
#include"node.h"
using namespace std;

int main()
{
    Node* root=new Node(100);

    Node* child1=new Node(200);
    Node* child2=new Node(300);
    Node* child1_1=new Node(400);
    Node* child1_2=new Node(500);

    root->append(child1);
    root->append(child2);

    child1->append(child1_1);
    child1->append(child1_2);

    cout<<root->count()<<endl;
    cout<<child1->getParent()->getValue()<<endl;
    return 0;
}
