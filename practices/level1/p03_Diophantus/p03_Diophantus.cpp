#include <iostream>
using namespace std;

void dio();
int main() {
	dio();
	system("pause");
	return 0;
}

void dio() {
	int fatherAge = 0, sonAge;
	bool finishThis = false;

	while (!finishThis) {
		fatherAge++;
		if (fatherAge % 6 == 0 && fatherAge % 7 == 0) {
			sonAge = fatherAge - (1.0 / 6)*fatherAge - (1.0 / 12)*fatherAge - (1.0 / 7)*fatherAge - 5;
			if ((sonAge >= 0) && (sonAge - 4) == (fatherAge / 2.0)) finishThis = true;
		}
	}
	cout << fatherAge - 4 << endl;
}