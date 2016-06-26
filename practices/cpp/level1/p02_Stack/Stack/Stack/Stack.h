#pragma once
template<class T>
class Stack
{
public:
	Stack(int size= 100):size(size)
	{
		top = 0;
		space = new T[size];
	}
	~Stack()
	{
		delete[]space;
	}
	bool push(const T&rhs)
	{
		if (!isFull())
		{
			space[++top] = rhs;
			return true;
		}
		return false;
	}
	T pop()
	{
		return space[top--];
	}
	bool isEmpty() const
	{
		return top == 0;
	}
	bool isFull() const
	{
		return top == size;
	}

private:
	int size;
	int top;
	T* space;
};

