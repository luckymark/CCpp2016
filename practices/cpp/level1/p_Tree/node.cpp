#include "node.h"

Node::Node(int value)
{
    data = value;
}

Node::~Node()
{
}

void Node::append(Node *node)
{
    childrenNodes.push_back(node);
    node->parent = this;
}

Node* Node::getParent()
{
    return this->parent;
}

int Node::getValue()
{
    return this->data;
}

int Node::count()
{
    int rnt = 1;
    for (std::vector<Node*>::iterator i = childrenNodes.begin(); i != childrenNodes.end(); ++i)
    {
        rnt += (*i)->count();
    }
    return rnt;
}
