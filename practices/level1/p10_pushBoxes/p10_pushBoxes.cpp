#include <iostream>
#include <conio.h>
using namespace std;
const int SIZE = 8;
int x = 3, y = 4;

char map[SIZE][SIZE] = {
	' ',' ',' ','#','#','#',' ',' ',
	' ',' ',' ','#','X','#',' ',' ',
	'#','#','#','#',' ','#',' ',' ',
	'#','X','@',' ','@','#','#','#',
	'#','#','#',' ','@',' ','X','#',
	' ',' ','#','@','#','#','#','#',
	' ',' ','#','X','#',' ',' ',' ',
	' ',' ','#','#','#',' ',' ',' '
};

bool isWin();
void mapGene();
void getKey();
void move(char dir);

int main() {
	mapGene();
	getKey();
	system("pause");
	return 0;
}

void mapGene() {
	system("cls");
	for (int line = 0; line <= SIZE - 1; line++) {
		for (int row = 0; row <= SIZE - 1; row++) {
			if (!(row == x&&line == y)) {
				cout << map[line][row];
			}
			else {
				cout << 'P';
			}
		}
		cout << endl;
	}

}
bool isWin() {
	bool rt = true;//return rt after all
	for (int line = 0; line <= SIZE - 1; line++) {
		for (int row = 0; row <= SIZE - 1; row++) {
			if (map[line][row] == 'X') {
				rt = false;
			}
		}
	}
	return rt;
}

void getKey() {
	char dir;
	while (1) {
		if (_kbhit() != 0) {
			dir = _getch();
			if (dir == 'w' || dir == 'a' || dir == 's' || dir == 'd') {
				move(dir);
				mapGene();
				if (isWin()) {
					cout << "you had win";
					return;
				}
			}
		}
	}
}


void move(char dir) {
	switch (dir)
	{
	case 'a': {
		if (map[y][x - 1] != '#') {
			x--;
		}
		if ((map[y][x] == '@') && (map[y][x - 1] != '#')) {
			map[y][x] = ' ';
			map[y][x - 1] = '@';
		}
		if (map[y][x] == '@') {
			x++;
		}
		break;
	}
	case 'd': {
		if (map[y][x + 1] != '#') {
			x++;
		}
		if ((map[y][x] == '@') && (map[y][x + 1] != '#')) {
			map[y][x] = ' ';
			map[y][x + 1] = '@';
		}
		if (map[y][x] == '@') {
			x--;
		}
		break;
	}
	case 's': {
		if (map[y + 1][x] != '#') {
			y++;
		}
		if ((map[y][x] == '@') && (map[y + 1][x] != '#')) {
			map[y][x] = ' ';
			map[y + 1][x] = '@';
		}
		if (map[y][x] == '@') {
			y--;
		}
		break;
	}
	case 'w': {
		if (map[y - 1][x] != '#') {
			y--;
		}
		if ((map[y][x] == '@') && (map[y - 1][x] != '#')) {
			map[y][x] = ' ';
			map[y - 1][x] = '@';
		}
		if (map[y][x] == '@') {
			y++;
		}
		break;
	}
	}
}
