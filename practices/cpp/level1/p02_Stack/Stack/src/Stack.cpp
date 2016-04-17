#include "Stack.h"

Stack::Stack()
{
    head=new node;
    head->pre=nullptr;
}
void Stack::push(int v)
{
    top++;
    node *now=new node;
    now->value=v;
    head->next=now;
    now->pre=head;
    head=head->next;
}
int Stack::pop()
{
    top--;
    head=head->pre;
    delete head->next;
    return top;
}
bool Stack::isEmpty()
{
    return top==0;
}
int Stack::getTop()
{
    return head->value;
}
