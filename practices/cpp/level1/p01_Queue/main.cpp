#include <iostream>
#include "Queue.h"
using namespace::std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Queue queue;
	int n;
	cin>>n;
	if(!queue.isFull())
	{
		queue.append(n);
	}
	if(!queue.isEmpty())
	{
		n=queue.pop();
		cout<<n<<endl;
	}
	return 0;
}
