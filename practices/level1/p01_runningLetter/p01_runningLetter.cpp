#include <iostream>
#include <string>

using namespace std;
int main() {

	string Input;
	int otmp, itmp;
	system("mode con cols=180");
	cin >> Input;
	int num = 0;
	bool turn = true;
	while (1) {
		if (turn) {
			for (otmp = 0; otmp <= 180 - Input.length()-1; otmp++) {
				for (itmp = 0; itmp <= otmp; itmp++) {
					cout << ' ';
				}
				cout << Input;
				system("cls");
			}
		}
		else {
			for (otmp = 180 - Input.length()-1; otmp >= 0; otmp--) {
				for (itmp = 0; itmp <= otmp; itmp++) {
					cout << ' ';
				}
				cout << Input;
				system("cls");
			}
		}
		turn = !turn;
	}

	return 0;
}