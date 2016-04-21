#include <iostream>
#include <Windows.h>


using namespace std;

const int destination = 1000;
void selectPrime(bool result[]);


int main() {

	DWORD start_time = GetTickCount();
	bool result[destination + 1];

	selectPrime(result);

	DWORD End_time = GetTickCount();
	cout << "The Time Is: " << End_time - start_time << endl;
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

	for (otmp = 0; otmp <= destination; otmp++) {
		if (result[otmp]) {
			cout << otmp << endl;
		}
	}
}