#ifndef NODE_H
#define NODE_H
#include<vector>

class Node
{
    public:
        Node(int _value);
        virtual ~Node();
        void append(Node *node);
        int count();
        Node* getParent();
        int getValue();
    protected:
    private:
        int data;
        int childCount;
        std::vector<Node*> childrenNodes;
        Node *parent;
};

#endif // NODE_H
