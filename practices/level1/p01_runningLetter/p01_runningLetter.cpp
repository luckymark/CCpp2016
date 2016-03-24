#include <iostream>
#include <string>

using namespace std;
string Input;
const int mgc=80;
void run();

int main() {
	system("mode con cols=80");
	cin >> Input;
	run();

	return 0;
}

void run() {
	int otmp, itmp;
	bool turn = true;
	while (1) {
		if (turn) {
			for (otmp = 0; otmp <= mgc - Input.length() - 1; otmp++) {
				for (itmp = 0; itmp <= otmp; itmp++) {
					cout << ' ';
				}
				cout << Input;
				system("cls");
			}
		}
		else {
			for (otmp = mgc - Input.length() - 1; otmp >= 0; otmp--) {
				for (itmp = 0; itmp <= otmp; itmp++) {
					cout << ' ';
				}
				cout << Input;
				system("cls");
			}
		}
		turn = !turn;
	}
}