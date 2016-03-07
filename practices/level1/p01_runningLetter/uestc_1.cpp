


#include <iostream>
#include <string>

using namespace std;

int main()
{
	while (1)
	{
		string st,sp;
		st = "ETenal";
		sp = "";
		for (int i = 1; i <= 144; i++)
		{
			if (i<=72)
				sp.append(" ");
			else
				sp.erase(sp.length()-1);
			cout << sp<<st;
			system("cls");
		}
	
	}
    return 0;
}

