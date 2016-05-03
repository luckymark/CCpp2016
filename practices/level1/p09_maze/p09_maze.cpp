#include <iostream>
#include <conio.h>
using namespace std;
const int SIZE = 10;
int x = 1, y = 1;

const char MAZE_SAVE[SIZE][SIZE] = {
	'#','#','#','#','#','#','#','#','#','#',
	'#',' ',' ','#','#',' ',' ',' ','#','#',
	'#',' ',' ','#','#',' ','#',' ',' ','#',
	'#',' ',' ',' ','#',' ','#','#',' ','#',
	'#',' ','#',' ','#',' ','#','#',' ','#',
	'#',' ','#',' ','#',' ',' ','#',' ','#',
	'#',' ','#',' ',' ','#',' ','#',' ','#',
	'#',' ','#','#',' ','#',' ','#',' ','#',
	'#',' ',' ','#',' ',' ',' ','#','@','#',
	'#','#','#','#','#','#','#','#','#','#'
};

void mazeGene();
void getKey();
void move(char dir);

int main() {
	mazeGene();
	getKey();
	system("pause");
	return 0;
}

void mazeGene() {
	system("cls");
	for (int tmpo = 0; tmpo <= 9; tmpo++) {
		for (int tmpi = 0; tmpi <= 9; tmpi++) {
			if (!(tmpi == x&&tmpo == y)) {
				cout << MAZE_SAVE[tmpo][tmpi];
			}
			else {
				cout << '*';
			}
		}
		cout << endl;
	}

}

void getKey() {
	char dir;
	while (1) {
		if (_kbhit() != 0) {
			dir = _getch();
			if (dir == 'w' || dir == 'a' || dir == 's' || dir == 'd') {
				move(dir);
				mazeGene();
				if (MAZE_SAVE[y][x] == '@') {
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
		if (MAZE_SAVE[y][x - 1] != '#') x--;
		break;
	}
	case 'd': {
		if (MAZE_SAVE[y][x + 1] != '#') x++;
		break;
	}
	case 's': {
		if (MAZE_SAVE[y + 1][x] != '#') y++;
		break;
	}
	case 'w': {
		if (MAZE_SAVE[y - 1][x] != '#') y--;
		break;
	}
	}
}
