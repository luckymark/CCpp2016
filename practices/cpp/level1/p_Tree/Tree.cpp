#include "Tree.hpp"

int Tree::get_value() {
    return m_value;
}

void Tree::set_value(int value) {
    m_value = value;
}

void Tree::append() {
    auto child = new Tree;
    child->m_parent = this;
    m_childs.push_back(child);
}

int Tree::size() {
    int number = 1;
    for (auto t : m_childs) {
        number += t->size();
    }
    return number;
}

std::vector<Tree *> Tree::get_childs() {
    return m_childs;
}

Tree::~Tree() {
    for (auto e : m_childs) {
        delete e;
    }
}
