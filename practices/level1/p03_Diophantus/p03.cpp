#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
	for(int i=1;i<=1000;i++)
	{
		double child=i/6.0;
		double teen=i/12.0;
		double sigle=i/7.0;
		double sonborn=child+sigle+teen+5.0;
		double sondeath=i-4.0;
		if((sondeath-sonborn)*2.0==i)
		{
			cout<<i-4<<endl;
			break;
		}
	}
	return 0;
}
