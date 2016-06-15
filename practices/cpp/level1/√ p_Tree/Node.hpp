//
// Created by Administrator on 2016/6/9.
//

#ifndef P_TREE_NODE_H
#define P_TREE_NODE_H


class Node {
private:
    int data;
    int mark;
    int parent;
public:
    Node(int mData,int mMark,int mParent) {
        data=mData;
        mark=mMark;
        parent=mParent;
    }

    ~Node() { }

    int getMark(){
        return mark;
    }
    int getData(){
        return data;
    }
    int getParent(){
        return parent;
    }
};


#endif //P_TREE_NODE_H
