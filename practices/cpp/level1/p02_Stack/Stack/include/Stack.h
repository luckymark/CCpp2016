#ifndef STACK_H
#define STACK_H

struct unit{
      unit* next;
      unit* last;
      int value;
      int number;
};


class Stack
{
    public:
        bool isEmpty();
        void push(int item);
        int pop();
        Stack();
        virtual ~Stack();

    protected:

    private:
        unit* top;
};

#endif // STACK_H
;
