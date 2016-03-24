#include <iostream>
#include <Windows.h>
using namespace std;

long num = 0;

void move(char fm, char to);
void hanoi(int n, char from, char base, char to);

int main() {
	int n;
	DWORD StartTime = GetTickCount64();

	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	cout << "CalCount: " << num << endl;
	DWORD EndTime = GetTickCount64();
	cout << "time: " << EndTime - StartTime << " ms";
	system("pause");
	return 0;
}

void move(char fm, char to) {
	num++;
	cout << "move from " << fm << " to " << to << endl;
}

void hanoi(int n, char from, char base, char to) {
	if (n == 1) {
		move(from, to);
		return;
	}
	else {
		hanoi(n - 1, from, to, base);
		move(from, to);
		hanoi(n - 1, base, from, to);
	}

}