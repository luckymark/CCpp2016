#define SIZE 10

#include<iostream>

using namespace std;

void showMaze(char maze[][11]);
bool move(char direction, char maze[][11], int* x, int* y);

int main()
{
	bool win = 0;
	char maze[SIZE][SIZE + 1] = {
		"##########",
		"I ########",
		"#  #######",
		"## #######",
		"## #######",
		"##   #####",
		"### ######",
		"### ######",
		"###      #",
		"########O#",
	};
	int x = 1, y = 0;
	int *w = &x, *z = &y;
	showMaze(maze);
	while (1) {
		char direction = getchar();
		win = move(direction, maze, w, z);
		if (win == 1)
			break;
	}
	system("pause");
	return 0;
}

bool move(char direction, char maze[][11], int* x, int* y)
{
	int i = 0, j = 0;
	switch (direction)
	{
	case 'w':
		i = -1;
		break;
	case 's':
		i = 1;
		break;
	case 'a':
		j = -1;
		break;
	case 'd':
		j = 1;
		break;
	default:
		break;
	}
	if (maze[*x + i][*y + j] == ' ')
	{
		maze[*x + i][*y + j] = 'I';
		maze[*x][*y] = ' ';
		*x = *x + i;
		*y = *y + j;
	}
	else
		if (maze[*x + i][*y + j] == 'X')
		{
			maze[*x + i][*y + j] = 'I';
			maze[*x][*y] = ' ';
			cout << "Win!" << endl;
			return 1;
		}
	system("cls");
	showMaze(maze);
	return 0;
}

void showMaze(char maze[][11])
{
	for (int i = 0; i < 10; i++)
		cout << maze[i] << endl;
}