#include <iostream>
#include <Windows.h>


using namespace std;

const int mag = 1000;
void PrimeSelect(bool fin[]);


int main() {
	
	DWORD start_time = GetTickCount();
	bool fin[mag + 1];

	PrimeSelect(fin);

	DWORD End_time = GetTickCount();
	cout << "The Time Is: " << End_time - start_time << endl;
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

	for (otmp = 0; otmp <= mag; otmp++) {
		if (fin[otmp]) cout << otmp << endl;
	}
}