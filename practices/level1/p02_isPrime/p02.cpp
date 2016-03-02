#include <bits/stdc++.h>
using namespace std;
bool check(int v)
{
	for(int i=2;i<=sqrt(v);i++)
		if(v%i==0)
			return false;
	return true;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(n==1)
			cout<<"Are you kidding?"<<endl;
		cout<<(check(n)?"Yes":"No")<<endl;
	}
	return 0;
}