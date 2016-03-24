#include <iostream>
using namespace std;


void dio();
int main() {
	dio();
	system("pause");
	return 0;
}

void dio() {
	int Fage = 0, Sage;
	bool jump = false;

	while (!jump) {
		Fage++;
		if (Fage % 6 == 0 && Fage % 7 == 0) {
			Sage = Fage - (1.0 / 6)*Fage - (1.0 / 12)*Fage - (1.0 / 7)*Fage - 5;
			if ((Sage >= 0) && (Sage - 4) == (Fage / 2.0)) jump = true;
		}
	}
	cout << Fage - 4 << endl;
}