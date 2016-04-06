#include <iostream>
#include <string>

using namespace std;
string contentText;
const int WIDTH_OF_CONSOLE = 80;
void run();

int main() {
	system("mode con cols=80");
	cin >> contentText;
	run();

	return 0;
}

void run() {
	int tmp, count = 0, border, blankAmount;
	border = WIDTH_OF_CONSOLE - contentText.length() - 1;
	count = border;
	while (1) {

		if (count > border) {
			count = count % (2 * border);
		}
		blankAmount = abs(count - border);
		for (tmp = 0; tmp <= blankAmount; tmp++) {
			cout << ' ';
		}
		cout << contentText;
		count++;
		system("cls");
	}
}