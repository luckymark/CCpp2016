#ifndef TREE_HPP__
#define TREE_HPP__

#include <vector>


class Tree {
private:
    int m_value = 0;
    Tree *m_parent = NULL;
    std::vector<Tree *> m_childs;
public:
    int get_value();
    void set_value(int value);
    void append();
    int size();
    std::vector<Tree *> get_childs();
    virtual ~Tree();
};

#endif
