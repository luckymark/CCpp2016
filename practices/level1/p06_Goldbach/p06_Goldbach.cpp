#include <iostream>

using namespace std;

const int mag = 100;
bool fin[mag + 1];

void PrimeSelect(bool fin[]);
bool gold();
void isTrue();

int main() {
	PrimeSelect(fin);
	isTrue();

	system("pause");
	return 0;
}


void PrimeSelect(bool fin[]) {
	int otmp, itmp;
	fin[0] = fin[1] = false;

	for (otmp = 2; otmp <= mag; otmp++) fin[otmp] = true;
	int end;
	for (otmp = 2; otmp <= (sqrt(mag)); otmp++) {
		end = floor((float)mag / otmp);
		for (itmp = 2; itmp <= end; itmp++) {
			if (otmp*itmp <= mag) fin[otmp*itmp] = false;
		}
	}

}

bool gold() {
	bool flag = true;
	for (int tmp = 0; tmp <= 100; tmp++) {
		if (fin[tmp]) {
			for (int itmp = 0; itmp <= tmp; itmp++) {
				if (!(fin[itmp] && fin[tmp - itmp])) flag = false;
			}
		}
	}
	return flag;
}

void isTrue() {
	if (gold) cout << "is true";
	else cout << "is false";
}