#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int a;
	cin >> a;
	bool flag = false;
	for (int i = 2; i <= sqrt(double(a)); i++)
		if (a % i == 0)
			flag = true;
	if (flag)
		cout << "不是质数" << endl;
	else
		cout << "是质数" << endl;
	system("pause");
}