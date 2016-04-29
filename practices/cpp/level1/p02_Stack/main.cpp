#include<iostream>
#include"Stack.h"
#define RANGE 100
using namespace std;
int main() 
{
    int capbility;
    cout<<"please input the size of the stack"<<endl;
    cin>>capbility;
    Stack stack(capbility);
    while (!stack.isFull(capbility)) 
	{
    	stack.push(RANGE);
    }
    while (!stack.isEmpty()) 
	{
    	int num;
    	num= stack.pop();
	    cout<<num<<endl;
    }
}
