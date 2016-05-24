#include <iostream>

using namespace std;

const int destination = 100;
bool result[destination + 1];

void selectPrime(bool result[]);
bool goldbachIsRight();
void outputAnswer();

int main() {
	selectPrime(result);
	outputAnswer();

	system("pause");
	return 0;
}


void selectPrime(bool result[]) {
	int otmp, itmp;
	result[0] = result[1] = false;

	for (otmp = 2; otmp <= destination; otmp++) result[otmp] = true;
	int end;
	for (otmp = 2; otmp <= (sqrt(destination)); otmp++) {
		end = floor((float)destination / otmp);
		for (itmp = 2; itmp <= end; itmp++) {
			if (otmp*itmp <= destination) {
				result[otmp*itmp] = false;
			}
		}
	}

}

bool goldbachIsRight() {
	bool flag = true;
	for (int tmp = 0; tmp <= 100; tmp++) {
		if (result[tmp]) {
			for (int itmp = 0; itmp <= tmp; itmp++) {
				if (!(result[itmp] && result[tmp - itmp])) {
					flag = false;
				}
			}
		}
	}
	return flag;
}

void outputAnswer() {
	if (goldbachIsRight) {
		cout << "is true";
	}
	else cout << "is false";
}